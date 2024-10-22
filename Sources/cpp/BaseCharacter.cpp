#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

BaseCharacter::~BaseCharacter()
{

}

void BaseCharacter::Move(Vector2 moveVec, float angle)
{
	// �������͂ɏ]���ăL�����N�^�[���ړ�
	if (moveVec.x != 0.0f || moveVec.y != 0.0f)
	{

		// �v�Z�p��VECTOR�ϐ�
		Vector2 temp;

		float sinParam = sinf(angle / 180.0f * DX_PI_F);
		float cosParam = cosf(angle / 180.0f * DX_PI_F);

		//temp.x = moveVector.x * cosParam + moveVector.z * sinParam;
		temp.x = moveVec.x * cosParam - moveVec.y * sinParam;
		temp.y = moveVec.x * sinParam + moveVec.y * cosParam;
		
		// �ړ���K��
		// oncePos = VAdd(status.m_position, temp);
	}
}

void BaseCharacter::Rotate()
{

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
	}
}

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}