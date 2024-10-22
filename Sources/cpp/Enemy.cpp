#include "../header/Enemy.h"
#include "../header/Player.h"
#include "../header/CollisionManager.h"

Enemy::Enemy()
{
	colManager = new CollisionManager();
}

// 敵の挙動
void Enemy::Proc()
{
	// ゲームマネージャーからプレイヤーの座標を取得
	Vector2 playerPos;

	Vector2 angle = status.m_position - playerPos;
	angle.normalize();

	// 常にプレイヤーの方向を向く
	Rotate(angle);

	//Move();

	// 射線が通っているなら
	if (colManager->CheckBetweenObject(status.m_position, playerPos))
	{
		Shot();
	}
	
}
