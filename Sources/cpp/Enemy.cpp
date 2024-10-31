#include "../header/Enemy.h"
#include "../header/Player.h"

Enemy::Enemy(Vector2 pos)
{
	status.m_position = pos;
	status.m_nextPosition = pos;
}

Enemy::~Enemy()
{

}

// 敵の挙動
void Enemy::Proc(BulletManager* bullet, InputManager* inputManager)
{
	// ゲームマネージャーからプレイヤーの座標を取得
	Vector2 playerPos;

	Vector2 angle = status.m_position - playerPos;
	angle.normalize();

	// 常にプレイヤーの方向を向く
	Rotate(angle);

	//Move();


	// 射線が通っているなら

	bullet->AddBullet(deviceNum, status);

}
