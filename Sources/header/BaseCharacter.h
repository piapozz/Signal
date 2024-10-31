#pragma once
#include "../header/BaseObject.h"
#include "BulletManager.h"
#include "InputManager.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
public:
	int deviceNum;						// �e�̊Ǘ��ȂǂɎg���ϐ�
	int playerNum;						// �ǂ̃v���C���[���ǂ̃R���g���[���[���g���̂����Ǘ�����

	BaseCharacter();					// �R���X�g���N�^
	~BaseCharacter();					// �f�X�g���N�^

	void SetPlayerNum(int playerNumber);
	void Rotate(Vector2 stickAngle);
	void Move();
	void Dodge();
	bool GetIsPlayer();
	void PowerUp();
	void StatusUp();

	virtual void Proc(BulletManager* bullet, InputManager* inputManager) = 0;

protected:
	Vector2 moveVec;

	int exp;					// �󂵂����̐����Ǘ�

	float speed = 1;			// ���@�̃X�s�[�h
	float dodgeSpeed;			// ����̑���
	float dodgeCount;			// ����̃N�[���^�C���Ǘ�
	float dodgeFlame;			// ����Ɏg���t���[����

	bool isPlayer;
	bool canDodge;
	bool dodgeNow;				// ������Ă����Ԃ�������

};