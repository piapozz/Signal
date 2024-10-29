#include "../header/CollisionManager.h"
#include "../header/StageManager.h"

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{

}

// ベースオブジェクトとベースオブジェクトの判定
bool CollisionManager::HitCheckBaseObj(BaseObject obj1, BaseObject obj2)
{
	// 座標と半径
	Vector2 pos1 = obj1.GetStatus().m_position;
	float radius1 = obj1.GetStatus().m_shapeSize;
	Vector2 pos2 = obj2.GetStatus().m_position;
	float radius2 = obj2.GetStatus().m_shapeSize;

	// 距離の差が半径の合計以下なら接触
	if (Vector2::Distance(pos1, pos2) >= (radius1 + radius2))
	{
		return true;
	}

	return false;
}

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

}

// プレイヤーと敵を判定する関数
void CollisionManager::HitCheck_Player_Player(std::vector<BaseObject> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < players.size(); j++)
		{
			if (i >= j) return;

			if (HitCheckBaseObj(players[i], players[j]))
			{
				// オブジェクトのhitFlagを立てる
			}
		}
	}
}

// プレイヤーと弾を判定する関数
void CollisionManager::HitCheck_Player_Bullet(std::vector<BaseObject> players, std::vector<BaseObject> bullets)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < bullets.size(); j++)
		{
			if (i >= j) return;

			if (HitCheckBaseObj(players[i], bullets[j]))
			{
				// オブジェクトのhitFlagを立てる
			}
		}
	}
}

// プレイヤーと箱を判定する関数
void CollisionManager::HitCheck_Player_Box(std::vector<BaseObject> players, std::vector<Box> boxs)
{

}

// 弾と箱を判定する関数
void CollisionManager::HitCheck_Bullet_Box(std::vector<BaseObject> bullets, std::vector<Box> boxs)
{

}