#pragma once
#include "../header/BaseObject.h"
#include "../header/InputManager.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
protected:
	InputManager* inputManager;

	float speed;				// 自機のスピード
	float dodgeCount;			// 回避のクールタイム管理
	int exp;					// 壊した箱の数を管理

	VECTOR oncePos;

	BaseCharacter();
	~BaseCharacter();

	void Move(VECTOR moveVec, float angle);
	void Rotate();
	void Shot();
	void Dodge(VECTOR moveVec, float angle);
	void PowerUp();
	void StatusUp();
};