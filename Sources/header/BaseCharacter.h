#pragma once
#include "../header/BaseObject.h"
#include "../header/InputManager.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
protected:
	InputManager* inputManager;

	int exp;					// �󂵂����̐����Ǘ�

	float speed;				// ���@�̃X�s�[�h
	float dodgeSpeed;			// ����̑���
	float dodgeCount;			// ����̃N�[���^�C���Ǘ�
	float dodgeFlame;			// ����Ɏg���t���[����

	bool canDodge;
	bool dodgeNow;				// ������Ă����Ԃ�������

	BaseCharacter();					// �R���X�g���N�^
	~BaseCharacter();					// �f�X�g���N�^

	void Move(Vector2 moveVec);
	void DodgeMove();
	void Rotate(Vector2 stickAngle);
	void Dodge(Vector2 moveVec);
	void PowerUp();
	void StatusUp();
	void UpdateHitJudge();
};