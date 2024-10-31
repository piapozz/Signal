#include "../header/CollisionManager.h"

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{

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
	if (Vector2::Distance(pos1, pos2) >= (radius1 + radius2))
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
	if ((objPos.x > vertexPos[2].x) && (objPos.x < vertexPos[0].x) && (objPos.y > vertexPos[2].y - radius) && (objPos.y < vertexPos[0].y + radius))
		return true;
	// 矩形のx領域判定
	if ((objPos.x > vertexPos[2].x - radius) && (objPos.x < vertexPos[0].x + radius) && (objPos.y > vertexPos[2].y) && (objPos.y < vertexPos[0].y))
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

// みかん
// 射線が通っているかレイで判定する関数
bool CollisionManager::CheckBetweenObject(Vector2 pos1, Vector2 pos2, std::vector<Box*> boxList)
{
	// すべての箱と判定
	for (int i = 0; i < boxList.size(); i++)
	{
		// 例外処理
		// 線分からの距離が接触しない距離ならスキップ
		if (false) continue;

		// すべての辺と判定
		for (int j = 0; j < 4; j++)
		{
			if (CheckLineCross(pos1, pos2, boxList[i]->GetVertexPos(j), boxList[i]->GetVertexPos((j + 1) % 4)) == true)
				return false;
		}
	}
	return true;
}

// 線分と線分が交わっているかを判定する関数
bool CollisionManager::CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2)
{
	return false;
}

// プレイヤーと敵を判定する関数
void CollisionManager::HitCheck_Player_Player(std::vector<BaseCharacter*> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < players.size(); j++)
		{
			if (i >= j) return;

			if (HitCheck_BaseObj(players[i], players[j]))
			{
				// オブジェクトのhitFlagを立てる
				players[i]->SetHitFlag(true);
				players[j]->SetHitFlag(true);
			}
		}
	}
}

// プレイヤーと弾を判定する関数
void CollisionManager::HitCheck_Player_Bullet(std::vector<BaseCharacter*> players , BulletManager *bullet)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < bullet->GetBulletList().size(); j++)
		{
			if (i == j) continue;
			for (int k = 0; k < bullet->GetBulletList()[j].m_BulletList.size(); k++)
			{
				if (HitCheck_BaseObj(players[i],bullet->GetBulletList()[j].m_BulletList[k]))
				{
					// ダメージ処理
					players[i]->TakeDamage(bullet->GetBulletList()[i].m_BulletList[j]->GetPower());
				}
			}
		}
	}
}

// プレイヤーと箱を判定する関数
void CollisionManager::HitCheck_Player_Box(std::vector<BaseCharacter*> players, std::vector<Box*> boxs)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < boxs.size(); j++)
		{
			if (HitCheck_BaseObj_Box(players[i], boxs[j]))
			{
				// オブジェクトのhitFlagを立てる
				players[i]->SetHitFlag(true);
				boxs[j]->SetHitFlag(true);
			}
		}
	}
}

// 弾と箱を判定する関数
void CollisionManager::HitCheck_Bullet_Box(std::vector<Box*> boxs, BulletManager* bullet)
{
	for (int i = 0; i < boxs.size(); i++)
	{
		for (int j = 0; j < bullet->GetBulletList().size(); j++)
		{
			for (int k = 0; k < bullet->GetBulletList()[j].m_BulletList.size(); k++)
			{
				if (!bullet->GetBulletList()[j].m_BulletList[k]->GetActive()) continue;

				if (HitCheck_BaseObj_Box(bullet->GetBulletList()[j].m_BulletList[k], boxs[i]))
				{
					// 壁かどうかで分岐
					if (boxs[j]->GetIsWall() == true)
						bullet->GetBulletList()[i].m_BulletList[j]->Destroy();
					else
						// ダメージ処理
						boxs[j]->TakeDamage(bullet->GetBulletList()[i].m_BulletList[j]->GetPower());
				}
			}
		}
	}
}

void CollisionManager::HitCheck_Everything(std::vector<BaseCharacter*> players, std::vector<Box*> boxs, BulletManager* bullet)
{
	HitCheck_Player_Player(players);
	HitCheck_Player_Bullet(players, bullet);
	HitCheck_Player_Box(players, boxs);
	HitCheck_Bullet_Box(boxs, bullet);
}