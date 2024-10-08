#pragma once
#include "BaseObject.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
protected:

	float speed;				// 自機のスピード
	float dodgeCount;			// 回避のクールタイム管理
	int exp;					// 壊した箱の数を管理

	BaseCharacter();
	~BaseCharacter();

	void Move(VECTOR moveVec, float angle);
	void Rotate();
	void Shot();
	void Dodge();
	void PowerUp();
	void StatusUp();
};