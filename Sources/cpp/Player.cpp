#include "../header/Player.h"

Player::Player(Vector2 pos)
{
	status.m_position = pos;
	status.m_nextPosition = pos;

	// �v���C���[�̐�����
	canMove = true;

	isPlayer = true;
}

Player::~Player()
{

}

void Player::Init(BulletManager* bullet, InputManager* input)
{
	bulletManager = bullet;
	inputManager = input;
}

// �v���C���[�̃��C������
void Player::Proc()
{
	DrawFormatString(15, 5, GetColor(0, 0, 0), "[Debug]");
	// ����ł��Ȃ������珈�������� ��isActive��true�̂Ƃ��͎���ł���
	if (status.m_isActive)
	{
		// �R���g���[���[�̏�Ԃ��X�V
		GetController();

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

		if (controller.m_RTrigger) bulletManager->AddBullet(deviceNum, status);

		// ���W���X�V
		// UpdatePosition();
	}

	// �̗͂�0�ɂȂ����Ƃ��v���C���[�͎��ɂ܂�
	if (status.m_life <= 0) status.m_isActive = false;
	
}

// �R���g���[���[�����X�V
void Player::GetController()
{
	controller.m_LStick = inputManager->GetStick(deviceNum, Stick::LEFT);
	controller.m_RStick = inputManager->GetStick(deviceNum, Stick::RIGHT);
	controller.m_LTrigger = inputManager->GetButton(deviceNum, Button::LEFT_TRIGGER);
	controller.m_RTrigger = inputManager->GetButton(deviceNum, Button::RIGHT_TRIGGER);
}