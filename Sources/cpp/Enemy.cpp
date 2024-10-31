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

// �G�̋���
void Enemy::Proc(BulletManager* bullet, InputManager* inputManager)
{
	// �Q�[���}�l�[�W���[����v���C���[�̍��W���擾
	Vector2 playerPos;

	Vector2 angle = status.m_position - playerPos;
	angle.normalize();

	// ��Ƀv���C���[�̕���������
	Rotate(angle);

	//Move();


	// �ː����ʂ��Ă���Ȃ�

	bullet->AddBullet(deviceNum, status);

}
