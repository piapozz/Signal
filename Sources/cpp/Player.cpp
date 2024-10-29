#include "../header/Player.h"

Player::Player()
{
	// �v���C���[�̐�����
	isDead = false;
	canMove = true;
}

Player::~Player()
{

}

// �v���C���[�̃��C������
void Player::Proc()
{
	// �����蔻��̍X�V
	UpdateHitJudge();

	// ����ł��Ȃ������珈�������� ��isDead��true�̂Ƃ��͎���ł���
	if (isDead != true)
	{
		// �R���g���[���[�̏�Ԃ��X�V
		GetController();

		// �����ړ��ł����Ԃ�������
		if (canMove)
		{
			// ����ړ���Ԃł͂Ȃ�������ʏ�ړ�������
			Move(controller.m_LStick);
		}

		// �v���C���[�̌�����ύX
		Rotate(controller.m_RStick);
	}

	// �̗͂�0�ɂȂ����Ƃ��v���C���[�͎��ɂ܂�
	if (status.m_life <= 0) isDead = true;
}

// �v���C���[�ɔԍ���U�蕪��
void Player::SetPlayerNum(int playerNumber)
{
	// �����ł�������ԍ����v���C���[�ԍ��ɐݒ�
	playerNum = playerNumber;
}

// �R���g���[���[�����X�V
void Player::GetController()
{
	controller.m_LStick = inputManager->GetStick(playerNum, Stick::LEFT);
	controller.m_RStick = inputManager->GetStick(playerNum, Stick::RIGHT);
}