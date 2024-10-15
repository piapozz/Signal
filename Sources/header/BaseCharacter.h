#pragma once
#include "../header/BaseObject.h"
#include "../header/InputManager.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
protected:
	InputManager* inputManager;

	float speed;				// ���@�̃X�s�[�h
	float dodgeCount;			// ����̃N�[���^�C���Ǘ�
	int exp;					// �󂵂����̐����Ǘ�

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