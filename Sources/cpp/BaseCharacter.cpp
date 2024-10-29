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
	nextPos.x = 0.0f;
	nextPos.y = 0.0f;

	// ����ړ���������
	if (dodgeNow)
	{
		// �����Ă�������ɋ����I�ɐi��
		nextPos.x = cos(status.m_angle) * dodgeSpeed;
		nextPos.y = sin(status.m_angle) * dodgeSpeed;
	}

	// �ʏ�ړ�
	else
	{
		// �΂߂ɓ��͂���Ă��Ȃ�������
		if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
		{
			// �ړ��x�N�g���ɃX�s�[�h�������Ă��̂܂܉��Z
			nextPos.x += moveVec.x * speed;
			nextPos.y += moveVec.y * speed;
		}

		// �΂ߓ��͂���Ă�����
		else
		{
			// �ړ��x�N�g���ɃX�s�[�h�������Ă��̂܂܉��Z
			nextPos.x += moveVec.x * speed / 0.5f;
			nextPos.y += moveVec.y * speed / 0.5f;
		}
	}
}

// ���ݍ��W�ɓK��
void BaseCharacter::UpdatePosition()
{
	// �ړ��\����W�ƃI�u�W�F�N�g�Ƃ̓����蔻������Ĉړ������������邩����i���̏�Ԃł͓����Ȃ��Ȃ�j
	if (hitObject != true)
	{
		// ���W���X�V
		status.m_position.x += nextPos.x;
		status.m_position.y += nextPos.y;
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
	// hitObject = collisionManager->HitCheck();
	// hitBullet = collisionManager->HitCheck();
}