#include "../header/CollisionManager.h"
#include "../header/StageManager.h"

// 法線
// オブジェクト同士の判定とBulletBaseとObjectBaseとの判定

// ベースオブジェクトとベースオブジェクトの判定
bool CollisionManager::HitCheck(BaseObject obj1, BaseObject obj2)
{
	// オブジェクトの形で処理を分岐
	// 両方円なら
	if (true)
	{
		// 座標と半径
		Vector2 pos1;
		float radius1;
		Vector2 pos2;
		float radius2;

		// 距離の差が半径の合計以下なら接触
		if (Vector2::Distance(pos1, pos2) >= (radius1 + radius2))
		{
			return true;
		}
	}

	return false;
}

// 射線が通っているかレイで判定する関数
bool CollisionManager::CheckBetweenObject(Vector2 pos1, Vector2 pos2)
{
	// すべての箱と判定
	for (int i = 0; i < 1; i++)
	{
		// 例外処理
		// 線分からの距離が接触しない距離ならスキップ
		if (false) continue;

		// すべての辺と判定
		for (int j = 0; j < 4; j++)
		{
			// 辺の線分
			Vector2 sideLine;
			// レイ
			Vector2 ray = pos1 - pos2;
			// 壁の辺とレイが交わっていたら接触
			if (false)
			{

			}
		}
	}
}

// 線分と線分が交わっているかを判定する関数
bool CollisionManager::CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2)
{

}