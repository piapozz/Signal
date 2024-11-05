#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

	hitObject = false;
	dodgeNow = false;

	speed = 1.0f;
}

BaseCharacter::~BaseCharacter()
{

}

// �ʏ�ړ�����
void BaseCharacter::Move()
{
	// ����ړ���������
	if (dodgeNow)
	{
		// �����Ă�������ɋ����I�ɐi��
		status.m_nextPosition.x = (status.m_position.x + cos(status.m_angle)) * dodgeSpeed;
		status.m_nextPosition.y = (status.m_position.y + sin(status.m_angle)) * dodgeSpeed;
	}

	// �ʏ�ړ�
	else
	{
		if (moveVec.x != 0.0f || moveVec.y != 0.0f)
		{
			// �ړ��x�N�g���̒������v�Z
			vecLength = sqrt(pow(moveVec.x, 2.0f) + pow(moveVec.y, 2.0f));

			// ���K�����ꂽ�ړ��x�N�g���ɃX�s�[�h�������Ď��̈ʒu���v�Z
			status.m_nextPosition.x = status.m_position.x + (moveVec.x / vecLength);
			status.m_nextPosition.y = status.m_position.y + (moveVec.y / vecLength);
		}
	}
}

// ������ς���
void BaseCharacter::Rotate(Vector2 stickAngle)
{
	// �ړ���������p�x���v�Z
	if (stickAngle.x != 0.0f || stickAngle.y != 0.0f)
	{
		// �p�x�v�Z���p�x�����W�A���ŕԂ�
		status.m_angle = atan2(stickAngle.y, stickAngle.x) * (180.0f / DX_PI_F);
	}
}

// �v���C���[�ɔԍ���U�蕪��
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// �����ł�������ԍ����v���C���[�ԍ��ɐݒ�
	playerNum = playerNumber;
}

// ����{�^���������ꂽ��ړ����@��Move����DodgeMove�ɐ؂�ւ���
void BaseCharacter::Dodge() { if (canDodge == true)dodgeNow = true; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

void BaseCharacter::GainExp(int expValue) { exp += expValue; }

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}