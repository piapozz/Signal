#pragma once
#include "BaseObject.h"
#include "BulletManager.h"
#include "InputManager.h"

class BaseCharacter : public BaseObject
{
private:
	float vecLength;					// �x�N�g���̒���
	float selecting;					// �I�𒆂̃R�}���h����

public:
	int deviceNum;						// �e�̊Ǘ��ȂǂɎg���ϐ�
	int playerNum;						// �ǂ̃v���C���[���ǂ̃R���g���[���[���g���̂����Ǘ�����
	int request;						// ���̗v����
	int levelUpCount;
	int powerUpCount;
	int statusUpCount;

	// int choicePower[CHOICE_POWER_MAX];
	// int choiceStatus[CHOICE_STATUS_MAX];

	std::vector<int> choicePower;
	std::vector<int> choiceStatus;

	bool choiceFlag;

	BaseCharacter();					// �R���X�g���N�^
	~BaseCharacter();					// �f�X�g���N�^

	void SetPlayerNum(int playerNumber);
	void Rotate(Vector2 stickAngle);
	void Move();
	void Dodge();
	bool GetIsPlayer();
	void GainExp(int expValue);
	int GetExpValue();
	void LevelUp();
	void PowerUp();
	void StatusUp();

	virtual void Proc() = 0;

protected:
	Vector2 moveVec;

	int exp;					// �󂵂����̐����Ǘ�

	float speed = 100;			// ���@�̃X�s�[�h
	float dodgeSpeed;			// ����̑���
	float dodgeCount;			// ����̃N�[���^�C���Ǘ�
	float dodgeFlame;			// ����Ɏg���t���[����

	bool isPlayer;
	bool canDodge;
	bool dodgeNow;				// ������Ă����Ԃ�������
};