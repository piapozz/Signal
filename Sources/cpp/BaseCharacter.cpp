#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
	hitObject = false;
	hitBullet = false;
}

BaseCharacter::~BaseCharacter()
{

}

// �ʏ�ړ�����
void BaseCharacter::Move(Vector2 moveVec)
{
	// �ړ���̗\����W
	Vector2 temp;

	// �΂߂ɓ��͂���Ă��Ȃ�������
	if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
	{
		/*
		if (moveVec.x >= 0) temp.x += moveVec.x * speed;
		if (moveVec.x <= 0) temp.x -= moveVec.x * speed;
		if (moveVec.y >= 0) temp.y += moveVec.y * speed;
		if (moveVec.y <= 0) temp.y -= moveVec.y * speed;
		*/

		// �ړ��x�N�g���ɃX�s�[�h�������Ă��̂܂܉��Z
		temp.x += moveVec.x * speed;
		temp.y += moveVec.y * speed;
	}

	// �΂ߓ��͂���Ă�����
	else
	{
		/*
		// �E��ړ�
		if (moveVec.x >= 0 && moveVec.y >= 0)
		{
			temp.x += moveVec.x * speed / 2.0f;
		}

		// ����ړ�
		if (moveVec.x <= 0 && moveVec.y >= 0)
		{
			temp.x += moveVec.x * speed / 2.0f;
		}

		// �E���ړ�
		if (moveVec.x >= 0 && moveVec.y <= 0)
		{
			temp.y += moveVec.y * speed;
		}

		// �����ړ�
		if (moveVec.x <= 0 && moveVec.y <= 0)
		{
			temp.y += moveVec.y * speed;
		}
		*/

		// �ړ��x�N�g���ɃX�s�[�h�������Ă��̂܂܉��Z
		temp.x += moveVec.x * speed / 0.5f;
		temp.y += moveVec.y * speed / 0.5f;
	}

	// �ړ��\����W�ƃI�u�W�F�N�g�Ƃ̓����蔻������Ĉړ������������邩����
	if (hitObject != true)
	{
		// ���W���X�V
		status.m_position.x += temp.x;
		status.m_position.y += temp.y;
	}
}

// ����ړ��̏���
void BaseCharacter::DodgeMove()
{
	Vector2 temp;

	// �����Ă�������ɋ����I�ɐi��
	temp.x = cos(status.m_angle) * dodgeSpeed;
	temp.y = sin(status.m_angle) * dodgeSpeed;

	// �ړ��\����W���I�u�W�F�N�g�ɂ������Ă��Ȃ�������
	if (hitObject != true)
	{
		// ���W���X�V
		status.m_position.x += temp.x;
		status.m_position.y += temp.y;
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

// ����{�^���������ꂽ��ړ����@��Move����DodgeMove�ɐ؂�ւ���
void BaseCharacter::Dodge(Vector2 moveVec) { if (canDodge == true)dodgeNow = true; }

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}

// �v���C���[���ێ����铖���蔻��̏����X�V
void BaseCharacter::UpdateHitJudge()
{
	// hitObject = �I�u�W�F�N�g�Ɣ�r����֐�
	// hitBullet = �e�Ɣ�r����֐�
}