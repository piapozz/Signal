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
	void UpdatePosition();
	void Rotate(Vector2 stickAngle);
	void Dodge(Vector2 moveVec);
	void PowerUp();
	void StatusUp();
	void UpdateHitJudge();
};