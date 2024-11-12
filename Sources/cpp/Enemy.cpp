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

void Enemy::Init(BulletManager* bullet, InputManager* inputManager, std::vector<BaseCharacter*> players)
{
	_pBulletManager = bullet;
	_pPlayers = players;
}

void Enemy::Init(CollisionManager* collisionManager)
{
	_pCollisionManager = collisionManager;
}

// 敵の挙動
void Enemy::Proc()
{
	Vector2 pos = status.m_position;

	// プレイヤーの中から一番近いプレイヤーを標的にする
	BaseCharacter* target = _pPlayers[0];
	Vector2 targetPos = target->status.m_position;
	float nearDistance = fabs(Vector2::Size(targetPos - pos));
	for (int i = 1; i < _pPlayers.size(); i++)
	{
		targetPos = _pPlayers[i]->status.m_position;

		float distance = fabs(Vector2::Size(targetPos - pos));

		if (distance != 0 && distance < nearDistance)
		{
			target = _pPlayers[i];
			nearDistance = distance;
		}
	}

	_isObstacle = _pCollisionManager->CheckHitRay(pos, targetPos);

	Vector2 angle = pos - targetPos;
	angle.normalize();

	// 移動量を決める
	moveVec = Vector2(0, 0);

	// 常にプレイヤーの方向を向く
	Rotate(angle);

	//Move();

	// 射撃
	if (_isObstacle == false)
		_pBulletManager->AddBullet(deviceNum, status);
}