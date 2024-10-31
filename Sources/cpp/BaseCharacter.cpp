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
	printfDx("moveVec.x%f\n", moveVec.x);
	printfDx("moveVec.y%f\n", moveVec.y);

	// status.m_nextPosition.x = 0.0f;
	// status.m_nextPosition.y = 0.0f;

	// ����ړ���������
	if (dodgeNow)
	{
		// �����Ă�������ɋ����I�ɐi��
		status.m_nextPosition.x = status.m_position.x + cos(status.m_angle) * dodgeSpeed;
		status.m_nextPosition.y = status.m_position.y + sin(status.m_angle) * dodgeSpeed;
	}

	// �ʏ�ړ�
	else
	{
		// �΂߂ɓ��͂���Ă��Ȃ�������
		if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
		{
			// �ړ��x�N�g���ɃX�s�[�h�������Ă��̂܂܉��Z
			status.m_nextPosition.x = status.m_position.x + moveVec.x * speed;
			status.m_nextPosition.y = status.m_position.y + moveVec.y * speed;
		}

		// �΂ߓ��͂���Ă�����
		else
		{
			// �ړ��x�N�g���ɃX�s�[�h�������Ă��̂܂܉��Z
			status.m_nextPosition.x = status.m_position.x + moveVec.x * speed / 0.5f;
			status.m_nextPosition.y = status.m_position.y + moveVec.y * speed / 0.5f;
		}
	}
}

// ������ς���
void BaseCharacter::Rotate(Vector2 stickAngle)
{
	// �ړ���������p�x���v�Z
	//if (stickAngle.x != 0.0f || stickAngle.y != 0.0f)
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

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}