#include "../header/CollisionManager.h"

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::Init(vector<BaseCharacter*> players, vector<Box*> boxs, BulletManager* bullet)
{
	_pPlayers = players;
	_pBoxs = boxs;
	_pBullet = bullet;
}

// オブジェクト同士が近距離にあるかを返す関数
bool CollisionManager::IsInProximity(BaseObject* obj1, BaseObject* obj2)
{
	float distance = Vector2::Distance(obj1->GetStatus().m_nextPosition, obj2->GetStatus().m_nextPosition);
	if (distance <= obj1->GetStatus().m_shapeSize / 2 + obj2->GetStatus().m_shapeSize / 2 + 50)
		return true;
	else
		return false;
}

// ベースオブジェクトとベースオブジェクトの判定
bool CollisionManager::HitCheck_BaseObj(BaseObject* obj1, BaseObject* obj2)
{
	// 座標と半径
	Vector2 pos1 = obj1->GetStatus().m_nextPosition;
	float radius1 = obj1->GetStatus().m_shapeSize;
	Vector2 pos2 = obj2->GetStatus().m_nextPosition;
	float radius2 = obj2->GetStatus().m_shapeSize;

	// 距離の差が半径の合計以下なら接触
	if (Vector2::Distance(pos1, pos2) <= (radius1 + radius2))
	{
		return true;
	}

	return false;
}

// ベースオブジェクトと箱の判定
bool CollisionManager::HitCheck_BaseObj_Box(BaseObject* obj, Box* box)
{
	Vector2 objPos = obj->GetStatus().m_nextPosition;
	Vector2 vertexPos[4];
	float radius = obj->GetStatus().m_shapeSize;
	for (int i = 0; i < 4; i++)
	{
		vertexPos[i] = box->GetVertexPos(i);
	}

	// 矩形のy領域判定
	if ((objPos.x < vertexPos[2].x + radius) && (objPos.x > vertexPos[0].x - radius) && (objPos.y > vertexPos[2].y - radius) && (objPos.y < vertexPos[0].y + radius))
		return true;
	// 矩形のx領域判定
	if ((objPos.x > vertexPos[2].x - radius) && (objPos.x < vertexPos[0].x + radius) && (objPos.y > vertexPos[2].y - radius) && (objPos.y < vertexPos[0].y + radius))
		return true;
	// 各頂点の領域判定
	for (int i = 0; i < 4; i++)
	{
		float distanceX = vertexPos[i].x - objPos.x;
		float distanceY = vertexPos[i].y - objPos.y;

		if (powf(distanceX, 2) + powf(distanceY, 2) < powf(radius, 2))
		{
			return true;
		}
	}

	return false;
}

// 射線が通っているかレイで判定する関数
bool CollisionManager::CheckHitRay(Vector2 pos1, Vector2 pos2)
{
	// すべての箱と判定
	for (int i = 0; i < _pBoxs.size(); i++)
	{
		// 例外処理
		// 線分からの距離が接触しない距離ならスキップ
		//if (false) continue;

		// すべての辺と判定
		for (int j = 0; j < 4; j++)
		{
			// 接触していたらfalse
			if (CheckLineCross(pos1, pos2, _pBoxs[i]->GetVertexPos(j), _pBoxs[i]->GetVertexPos((j + 1) % 4)) == true)
				return false;
		}
	}
	// どの箱とも接触していないならtrue
	return true;
}

// 線分と線分が交わっているかを判定する関数
bool CollisionManager::CheckLineCross(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
	// 外積を使って計算
	// グループ①
	Vector2 a_to_b = b - a;
	Vector2 a_to_c = c - a;
	Vector2 a_to_d = d - a;

	float cross1 = Vector2::Cross(a_to_b, a_to_c);
	float cross2 = Vector2::Cross(a_to_b, a_to_d);

	if (cross1 * cross2 > 0)
		return false;

	// グループ②
	Vector2 c_to_d = d - c;
	Vector2 c_to_a = a - c;
	Vector2 c_to_b = b - c;

	cross1 = Vector2::Cross(c_to_d, c_to_a);
	cross2 = Vector2::Cross(c_to_d, c_to_b);

	if (cross1 * cross2 > 0)
		return false;

	return true;
}

// プレイヤーと敵を判定する関数
void CollisionManager::HitCheck_Player_Player(BaseCharacter* player_1, BaseCharacter* player_2)
{
	if (HitCheck_BaseObj(player_1, player_2) == true)
	{
		// オブジェクトのhitFlagを立てる
		player_1->SetHitFlag(true);
		player_2->SetHitFlag(true);
	}
}

// プレイヤーと弾を判定する関数
void CollisionManager::HitCheck_Player_Bullet(BaseCharacter* player , MainBullet *bullet)
{		
	// 当たってたら
	if (HitCheck_BaseObj(player, bullet) == true)
	{
		std::vector<BaseObject*> hitCharaList = bullet->hitCharObject;
		// すでに当たっているオブジェクトならスキップ
		for (int i = 0; i < hitCharaList.size(); i++)
		{
			if (player == hitCharaList[i])
			{
				return;
			}
		}

		// ダメージ処理
		player->TakeDamage(bullet->GetDamage());
		// 効果音
		AudioManager::GetInstance().PlaySE(SEName::DAMAGE);
		// 当たったオブジェクトを渡す
		bullet->hitCharObject.push_back(player);
		// 着弾処理
		bullet->Impact(ObjectType::PLAYER);
	}
}

// プレイヤーと爆発を判定する関数
void CollisionManager::HitCheck_Player_Explosion(BaseCharacter* player, Explosion* explosion)
{
	// 当たってたら
	if (HitCheck_BaseObj(player, explosion) == true)
	{
		std::vector<BaseObject*> hitCharaList = explosion->hitCharObject;
		// すでに当たっているオブジェクトならスキップし、
		// 当たっているオブジェクトを更新
		for (int i = 0; i < hitCharaList.size(); i++)
		{
			if (player == hitCharaList[i])
			{
				return;
			}
		}

		// ダメージ処理
		player->TakeDamage(explosion->GetDamage());
		// 当たったオブジェクトを渡す
		explosion->hitCharObject.push_back(player);
	}
}

// プレイヤーと箱を判定する関数
void CollisionManager::HitCheck_Player_Box(BaseCharacter* player, Box* box)
{
	if (HitCheck_BaseObj_Box(player, box) == true)
	{
		// オブジェクトのhitFlagを立てる
		player->SetHitFlag(true);
	}
}

// 弾と箱を判定する関数
bool CollisionManager::HitCheck_Bullet_Box(MainBullet* bullet, Box* box)
{
	bool result = false;

	if (HitCheck_BaseObj_Box(bullet, box) == true)
	{
		// ダメージを与えているならスキップ
		std::vector<Box*> hitBoxList = bullet->hitBoxObject;
		bool isHit = false;
		for (int i = 0; i < hitBoxList.size(); i++)
		{
			if (box == hitBoxList[i])
				return result;
		}

		ObjectType objType = ObjectType::WALL;

		// 箱なら
		if (box->GetIsWall() == false)
		{
			objType = ObjectType::BOX;

			// ダメージ処理、倒しているなら
			if (box->TakeDamage(bullet->GetDamage()) == true)
				result = true;
		}

		// 当たったオブジェクトを渡す
		bullet->hitBoxObject.push_back(box);

		AudioManager::GetInstance().PlaySE(SEName::IMPACT);

		// 着弾処理
		bullet->Impact(objType);
	}

	return result;
}

// 爆発と箱を判定する関数
bool CollisionManager::HitCheck_Explosion_Box(Explosion* explosion, Box* box)
{
	bool result = false;

	if (HitCheck_BaseObj_Box(explosion, box) == true)
	{
		// ダメージを与えているならスキップ
		std::vector<Box*> hitBoxList = explosion->hitBoxObject;
		bool isHit = false;
		for (int i = 0; i < hitBoxList.size(); i++)
		{
			if (box == hitBoxList[i])
				return result;
		}

		ObjectType objType = ObjectType::WALL;

		// 箱なら
		if (box->GetIsWall() == false)
		{
			objType = ObjectType::BOX;

			// ダメージ処理、倒しているなら
			if (box->TakeDamage(explosion->GetDamage()) == true)
				result = true;
		}

		// 当たったオブジェクトを渡す
		explosion->hitBoxObject.push_back(box);
	}

	return result;
}

// すべてのオブジェクトを判定する関数
void CollisionManager::HitCheck_Everything()
{
	// プレイヤーの当たり判定
	for (int p1 = 0; p1 < _pPlayers.size(); p1++)
	{
		BaseCharacter* player_1 = _pPlayers[p1];

		// プレイヤーごとの判定
		for (int p2 = 0; p2 < _pPlayers.size(); p2++)
		{
			// 同じ組み合わせはスキップ
			if (p1 == p2) continue;
			BaseCharacter* player_2 = _pPlayers[p2];

			// ほかプレイヤーとの当たり判定
			if (IsInProximity(player_1, player_2) == true)
				// プレイヤーとプレイヤー
				HitCheck_Player_Player(player_1, player_2);

			// 弾との判定
			std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p2].m_BulletList;
			std::vector<Explosion*> explosionList = _pBullet->GetBulletList()[p2].m_ExplosionList;

			// 弾のループ
			for (int bu = 0; bu < bulletList.size(); bu++)
			{
				MainBullet* bullet = bulletList[bu];
				// 弾が非アクティブならスキップ
				if (!bullet->GetActive()) continue;

				// プレイヤーと弾
				if (IsInProximity(player_1, bullet) == true)
					HitCheck_Player_Bullet(player_1, bullet);
			}

			// 爆発のループ
			for (int ex = 0; ex < explosionList.size(); ex++)
			{
				Explosion* explosion = explosionList[ex];
				// 爆発が非アクティブならスキップ
				if (!explosion->GetActive()) continue;

				// プレイヤーと爆発
				if (IsInProximity(player_1, explosion) == true)
					HitCheck_Player_Explosion(player_1, explosion);
			}
		}

		// boxとの判定
		for (int bo = 0; bo < _pBoxs.size(); bo++)
		{
			Box* box = _pBoxs[bo];
			// 箱が非アクティブならスキップ
			if (!box->GetActive()) continue;

			
			if (IsInProximity(player_1, box) == true)
			{
				HitCheck_Player_Box(player_1, box);
			}
		}
	}

	// boxと弾の判定
	for (int bo = 0; bo < _pBoxs.size(); bo++)
	{
		Box* box = _pBoxs[bo];
		// 箱が非アクティブならスキップ
		if (!box->GetActive()) continue;

		// プレイヤーの数繰り返す
		for (int p2 = 0; p2 < _pPlayers.size(); p2++)
		{
			BaseCharacter* player_2 = _pPlayers[p2];

			std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p2].m_BulletList;
			std::vector<Explosion*> explosionList = _pBullet->GetBulletList()[p2].m_ExplosionList;

			// 弾のループ
			for (int bu = 0; bu < bulletList.size(); bu++)
			{
				MainBullet* bullet = bulletList[bu];
				// 弾が非アクティブならスキップ
				if (!bullet->GetActive()) continue;

				if (IsInProximity(bullet, box) == true)
					if (HitCheck_Bullet_Box(bullet, box))
						player_2->GainExp(box->GetExp());
			}

			// 爆発のループ
			for (int ex = 0; ex < explosionList.size(); ex++)
			{
				Explosion* explosion = explosionList[ex];
				// 爆発が非アクティブならスキップ
				if (!explosion->GetActive()) continue;

				if (IsInProximity(explosion, box) == true)
					if (HitCheck_Explosion_Box(explosion, box))
						player_2->GainExp(box->GetExp());
			}
		}
	}
}

// 弾が当たったオブジェクトを更新する
void CollisionManager::UpdateHitObj()
{
	// プレイヤーごとの判定
	for (int p2 = 0; p2 < _pPlayers.size(); p2++)
	{
		std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p2].m_BulletList;
		// 弾のループ
		for (int bu = 0; bu < bulletList.size(); bu++)
		{
			// プレイヤーとの判定
			std::vector<BaseObject*>& hitCharaList = bulletList[bu]->hitCharObject;
			for (int chara = hitCharaList.size() - 1; chara >= 0; chara--)
			{
				// プレイヤーが接触していないならリストから削除
				if (!HitCheck_BaseObj(bulletList[bu], hitCharaList[chara]))
					hitCharaList.erase(hitCharaList.begin() + chara);
			}

			// boxとの判定
			std::vector<Box*>& hitBoxList = bulletList[bu]->hitBoxObject;
			for (int box = hitBoxList.size() - 1; box >= 0; box--)
			{
				// プレイヤーが接触していないならリストから削除
				if (!HitCheck_BaseObj_Box(bulletList[bu], hitBoxList[box]))
					hitBoxList.erase(hitBoxList.begin() + box);
			}
		}

		std::vector<Explosion*>explosionList = _pBullet->GetBulletList()[p2].m_ExplosionList;
		// 爆発のループ
		for (int ex = 0; ex < explosionList.size(); ex++)
		{
			// プレイヤーとの判定
			std::vector<BaseObject*>& hitCharaList = explosionList[ex]->hitCharObject;
			for (int chara = hitCharaList.size() - 1; chara >= 0; chara--)
			{
				// プレイヤーが接触していないならリストから削除
				if (!HitCheck_BaseObj(explosionList[ex], hitCharaList[chara]))
					hitCharaList.erase(hitCharaList.begin() + chara);
			}

			// boxとの判定
			std::vector<Box*>& hitBoxList = explosionList[ex]->hitBoxObject;
			for (int box = hitBoxList.size() - 1; box >= 0; box--)
			{
				// プレイヤーが接触していないならリストから削除
				if (!HitCheck_BaseObj_Box(explosionList[ex], hitBoxList[box]))
					hitBoxList.erase(hitBoxList.begin() + box);
			}
		}
	}
}

// 箱とほかのオブジェクトの接触を判定する関数
bool CollisionManager::HitCheckBox_Other(Box* box)
{
	// プレイヤーとの判定
	for (int p = 0; p < _pPlayers.size(); p++)
	{
		BaseCharacter* player = _pPlayers[p];
		if (HitCheck_BaseObj_Box(player, box))
			return true;

		// 弾との判定
		std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p].m_BulletList;
		for (int b = 0; b < bulletList.size(); b++)
		{
			MainBullet* bullet = bulletList[b];
			// 弾が非アクティブならスキップ
			if (!bullet->GetActive()) continue;

			if (HitCheck_BaseObj_Box(bullet, box))
				return true;
		}
	}

	return false;
}