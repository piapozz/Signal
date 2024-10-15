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

	Vector2 oncePos;

	BaseCharacter();
	~BaseCharacter();

	void Move(Vector2 moveVec, float angle);
	void Rotate(Vector2 stickAngle);
	void Shot();
	void Dodge(Vector2 moveVec, float angle);
	void PowerUp();
	void StatusUp();
	void UpdateHitJudge();
};