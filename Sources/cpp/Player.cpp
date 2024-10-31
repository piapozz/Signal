#include "../header/Player.h"

Player::Player(Vector2 pos)
{
	status.m_position = pos;
	status.m_nextPosition = pos;

	// �v���C���[�̐�����
	isDead = false;
	canMove = true;

	isPlayer = true;
}

Player::~Player()
{

}

// �v���C���[�̃��C������
void Player::Proc(BulletManager* bullet, InputManager* inputManager)
{
	
	// ����ł��Ȃ������珈�������� ��isDead��true�̂Ƃ��͎���ł���
	// if (isDead != true)
	{
		// �R���g���[���[�̏�Ԃ��X�V
		GetController(inputManager);

		moveVec = controller.m_LStick;

		// �����������Ă�����������
		if (controller.m_LTrigger)Dodge();
		
		// �����ړ��ł����Ԃ�������
		if (canMove)
		{
			// ����ړ���Ԃł͂Ȃ�������ʏ�ړ�����������Ԃ�������������
			Move();
		}

		// �v���C���[�̌�����ύX
		Rotate(controller.m_RStick);

		if (controller.m_RTrigger) bullet->AddBullet(deviceNum, status);

		// ���W���X�V
		// UpdatePosition();
	}

	// �̗͂�0�ɂȂ����Ƃ��v���C���[�͎��ɂ܂�
	if (status.m_life <= 0) isDead = true;
	
}

// �R���g���[���[�����X�V
void Player::GetController(InputManager* inputManager)
{
	controller.m_LStick = inputManager->GetStick(deviceNum, Stick::LEFT);
	controller.m_RStick = inputManager->GetStick(deviceNum, Stick::RIGHT);
	controller.m_LTrigger = inputManager->GetButton(deviceNum, Button::LEFT_TRIGGER);
	controller.m_RTrigger = inputManager->GetButton(deviceNum, Button::RIGHT_TRIGGER);
}