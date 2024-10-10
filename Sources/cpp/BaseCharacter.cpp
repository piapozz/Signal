#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

BaseCharacter::~BaseCharacter()
{

}

void BaseCharacter::Move(VECTOR moveVec, float angle)
{
	// �������͂ɏ]���ăL�����N�^�[���ړ�
	if (moveVec.x != 0.0f || moveVec.z != 0.0f)
	{

		// �v�Z�p��VECTOR�ϐ�
		VECTOR temp;

		float sinParam = sinf(angle / 180.0f * DX_PI_F);
		float cosParam = cosf(angle / 180.0f * DX_PI_F);

		//temp.x = moveVector.x * cosParam + moveVector.z * sinParam;
		temp.x = moveVec.x * cosParam - moveVec.z * sinParam;
		temp.y = moveVec.x * sinParam + moveVec.z * cosParam;
		
		// �ړ���K��
		oncePos = VAdd(status.m_position, temp);
	}
}

void BaseCharacter::Rotate()
{

}

void BaseCharacter::Shot()
{

}

void BaseCharacter::Dodge(VECTOR moveVec, float angle)
{
	// �ړ������Ɍ������ĉ��������
	if (moveVec.x != 0.0f || moveVec.z != 0.0f)
	{
		// �v�Z�p��VECTOR�ϐ�
		VECTOR temp;

		float sinParam = sinf(angle / 180.0f * DX_PI_F);
		float cosParam = cosf(angle / 180.0f * DX_PI_F);

		temp.x = moveVec.x * cosParam - moveVec.z * sinParam;
		temp.y = moveVec.x * sinParam + moveVec.z * cosParam;
	}
}

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}