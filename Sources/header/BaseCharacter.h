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
	int lotteryPowerCount;				// �p���[�𒊑I�ł����
	int lotteryStatusCount;				// �X�e�[�^�X���I�ł����

	std::vector<int> choicePower;		// �p���[�A�b�v�̑I�������i�[
	std::vector<int> choiceStatus;		// �X�e�[�^�X�A�b�v�̑I�������i�[

	bool canLottery;					// ���I���s�����Ƃ��ł��邩�̊Ǘ�
	bool choosePower;					// �p���[�̋��������s���Ă邩�ǂ���
	bool chooseStatus;					// �X�e�[�^�X�̋��������s���Ă��邩�ǂ���

	BaseCharacter();					// �R���X�g���N�^
	~BaseCharacter();					// �f�X�g���N�^

	void Rotate(Vector2 stickAngle);
	void Move();
	void Dodge();
	void LevelUp() {};
	void ObserveExp();
	void LotteryStatus();
	void LotteryPower();
	void ChooseBonus(int selectedButton);

	// �l�̎擾��ύX���s���֐�
	bool GetIsPlayer();
	int GetExpValue();
	void GainExp(int expValue);
	Vector2 GetPlayerPos();
	int GetChooceFlag();
	void SetPlayerNum(int playerNumber);

	virtual void Proc() = 0;

protected:
	BulletManager* bullet;

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