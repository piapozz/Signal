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