#include "../header/Enemy.h"
#include "../header/Player.h"
#include "../header/CollisionManager.h"

Enemy::Enemy()
{
	colManager = new CollisionManager();
}

// �G�̋���
void Enemy::Proc()
{
	// �Q�[���}�l�[�W���[����v���C���[�̍��W���擾
	Vector2 playerPos;

	Vector2 angle = status.m_position - playerPos;
	angle.normalize();

	// ��Ƀv���C���[�̕���������
	Rotate(angle);

	//Move();

	// �ː����ʂ��Ă���Ȃ�
	if (colManager->CheckBetweenObject(status.m_position, playerPos))
	{
		Shot();
	}
	
}
