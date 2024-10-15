#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

BaseCharacter::~BaseCharacter()
{

}

// �ʏ�ړ�����
void BaseCharacter::Move(Vector2 moveVec, float angle)
{
	// �ړ���̗\����W
	Vector2 temp;

	// �΂߂ɓ��͂���Ă��Ȃ�������
	if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
	{
		if (moveVec.x >= 0) temp.x += moveVec.x * speed;
		if (moveVec.x <= 0) temp.x -= moveVec.x * speed;
		if (moveVec.y >= 0) temp.y += moveVec.y * speed;
		if (moveVec.y <= 0) temp.y -= moveVec.y * speed;
	}

	// �΂ߓ��͂���Ă�����
	else
	{
		if (moveVec.x >= 0 && moveVec.y >= 0) temp.x += moveVec.x * speed;
		if (moveVec.x <= 0 && moveVec.y >= 0) temp.x -= moveVec.x * speed;
		if (moveVec.x >= 0 && moveVec.y <= 0) temp.y += moveVec.y * speed;
		if (moveVec.x <= 0 && moveVec.y <= 0) temp.y -= moveVec.y * speed;
	}
	// �ړ��\����W�ƃI�u�W�F�N�g�Ƃ̓����蔻������Ĉړ������������邩����
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
	// �������͂ɏ]���ăL�����N�^�[���ړ�
	if (stickAngle.x != 0.0f || stickAngle.y != 0.0f)
	{	
		
	}
}

void BaseCharacter::Shot()
{

}

void BaseCharacter::Dodge(Vector2 moveVec, float angle)
{
	// �ړ������Ɍ������ĉ��������
	if (moveVec.x != 0.0f || moveVec.y != 0.0f)
	{
		// �v�Z�p��VECTOR�ϐ�
		Vector2 temp;

		float sinParam = sinf(angle / 180.0f * DX_PI_F);
		float cosParam = cosf(angle / 180.0f * DX_PI_F);


		temp.x = moveVec.x * cosParam - moveVec.y * sinParam * 2.0f;
		temp.y = moveVec.x * sinParam + moveVec.y * cosParam * 2.0f;

		// �����蔻��ɂ���Ď��g�̏ꏊ���X�V���邩�����߂�
	}
}

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