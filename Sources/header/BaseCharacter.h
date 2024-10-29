#pragma once
#include "../header/BaseObject.h"
#include "../header/InputManager.h"
#include "../header/CollisionManager.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
public:
	BaseCharacter();					// �R���X�g���N�^
	~BaseCharacter();					// �f�X�g���N�^

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

	void Move(Vector2 moveVec);
	void UpdatePosition();
	void Rotate(Vector2 stickAngle);
	void Dodge(Vector2 moveVec);
	void PowerUp();
	void StatusUp();
};