#pragma once
#include "../header/BaseObject.h"
#include "../header/InputManager.h"
#include "../header/CollisionManager.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
private:
	Vector2 tempPos;

protected:
	InputManager* inputManager;
	CollisionManager* collisionManager;

	int exp;					// 壊した箱の数を管理

	float speed;				// 自機のスピード
	float dodgeSpeed;			// 回避の速さ
	float dodgeCount;			// 回避のクールタイム管理
	float dodgeFlame;			// 回避に使うフレーム数

	bool canDodge;
	bool dodgeNow;				// 回避している状態かを見る

	BaseCharacter();					// コンストラクタ
	~BaseCharacter();					// デストラクタ

	void Move(Vector2 moveVec);
	void UpdatePosition();
	void Rotate(Vector2 stickAngle);
	void Dodge(Vector2 moveVec);
	void PowerUp();
	void StatusUp();
	void UpdateHitJudge();
};