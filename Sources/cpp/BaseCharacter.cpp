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

		temp.y = 0.0f;
		temp.z = moveVec.x * sinParam + moveVec.z * cosParam;
	}
}

void BaseCharacter::Rotate()
{

}

void BaseCharacter::Shot()
{

}

void BaseCharacter::Dodge()
{

}

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}