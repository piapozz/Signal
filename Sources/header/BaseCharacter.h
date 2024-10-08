#pragma once
#include "BaseObject.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
protected:

	float speed;				// ���@�̃X�s�[�h
	float dodgeCount;			// ����̃N�[���^�C���Ǘ�
	int exp;					// �󂵂����̐����Ǘ�

	BaseCharacter();
	~BaseCharacter();

	void Move(VECTOR moveVec, float angle);
	void Rotate();
	void Shot();
	void Dodge();
	void PowerUp();
	void StatusUp();
};