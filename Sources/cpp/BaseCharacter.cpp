#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

BaseCharacter::~BaseCharacter()
{

}

void BaseCharacter::Move(VECTOR moveVec, float angle)
{
	// 方向入力に従ってキャラクターを移動
	if (moveVec.x != 0.0f || moveVec.z != 0.0f)
	{

		// 計算用のVECTOR変数
		VECTOR temp;

		float sinParam = sinf(angle / 180.0f * DX_PI_F);
		float cosParam = cosf(angle / 180.0f * DX_PI_F);

		//temp.x = moveVector.x * cosParam + moveVector.z * sinParam;
		temp.x = moveVec.x * cosParam - moveVec.z * sinParam;
		temp.y = moveVec.x * sinParam + moveVec.z * cosParam;
		
		// 移動を適応
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
	// 移動方向に向かって回避を実装
	if (moveVec.x != 0.0f || moveVec.z != 0.0f)
	{
		// 計算用のVECTOR変数
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