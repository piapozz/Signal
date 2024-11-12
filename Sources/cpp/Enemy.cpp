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

void Enemy::Init(BulletManager* bullet, InputManager* inputManager, std::vector<BaseCharacter*> players, CollisionManager* collisionManager)
{
	_pBulletManager = bullet;
	_pPlayers = players;
	_pCollisionManager = collisionManager;
}

// �G�̋���
void Enemy::Proc()
{
	// �v���C���[�̒������ԋ߂��v���C���[��W�I�ɂ���
	BaseCharacter* target = _pPlayers[0];
	float nearDistance = fabs(Vector2::Size(target->status.m_position - status.m_position));
	for (int i = 1; i < _pPlayers.size(); i++)
	{
		Vector2 targetPos = _pPlayers[i]->status.m_position;

		float distance = fabs(Vector2::Size(targetPos - status.m_position));

		if (distance != 0 && distance < nearDistance)
		{
			target = _pPlayers[i];
			nearDistance = distance;
		}
	}

	Vector2 playerPos = target->status.m_position;

	Vector2 angle = status.m_position - playerPos;
	angle.normalize();

	// �ړ��ʂ����߂�
	moveVec = Vector2(0, 0);

	// ��Ƀv���C���[�̕���������
	Rotate(angle);

	Move();

	// �ː����ʂ��Ă���Ȃ�
	if (_pCollisionManager->)
	_pBulletManager->AddBullet(deviceNum, status);
}
