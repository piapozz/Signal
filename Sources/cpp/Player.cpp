#include "../header/Player.h"

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

		// �ˌ����s��
		if (controller.m_RTrigger) bulletManager->AddBullet(deviceNum, status);

		// �o���l�����ċ����ł��邩�m�F
		ObserveExp();

		// �������e���{�^���őI��
		ChooseBonus(InputButtonToInt());


		// ���W���X�V
		// UpdatePosition();
	}

}

// �R���g���[���[�����X�V
void Player::GetController()
{
	controller.m_LStick = inputManager->GetStick(deviceNum, Stick::LEFT);
	controller.m_RStick = inputManager->GetStick(deviceNum, Stick::RIGHT);
	controller.m_LTrigger = inputManager->GetButton(deviceNum, Button::LEFT_TRIGGER);
	controller.m_RTrigger = inputManager->GetButton(deviceNum, Button::RIGHT_TRIGGER);
}

// �R���g���[���[�œ��͂��ꂽXYAB�{�^����int�^�ŕԂ�
int Player::InputButtonToInt()
{
	int value = (int)Cardinal::MAX;

	if (inputManager->CheckDownButton(deviceNum, Button::X)) value = (int)Cardinal::WEST;
	else if (inputManager->CheckDownButton(deviceNum, Button::Y)) value = (int)Cardinal::NORTH;
	else if (inputManager->CheckDownButton(deviceNum, Button::B)) value = (int)Cardinal::EAST;
	else if (inputManager->CheckDownButton(deviceNum, Button::A)) value = (int)Cardinal::SOUTH;

	printfDx("value %d\n", value);

	return value;
}