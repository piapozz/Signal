#pragma once
#include "BaseObject.h"
#include "BulletManager.h"
#include "InputManager.h"

class BaseCharacter : public BaseObject
{
private:
	float vecLength;					// �x�N�g���̒���
	float selecting;					// �I�𒆂̃R�}���h����

	float speed = 5;			// ���@�̃X�s�[�h
	float dodgeSpeed = 20;		// ����̑���
	float dodgeMoveCount;		// ����̈ړ����Ԃ��Ǘ�
	float dodgeCooltime;		// ����̃N�[���^�C�����Ǘ�
	float playerBombCount;

	int request;						// ���̗v����
	int lotteryPowerCount;				// �p���[�𒊑I�ł����
	int lotteryStatusCount;				// �X�e�[�^�X���I�ł����

	bool canLottery;					// ���I���s�����Ƃ��ł��邩�̊Ǘ�
	bool choosePower;					// �p���[�̋��������s���Ă邩�ǂ���
	bool chooseStatus;					// �X�e�[�^�X�̋��������s���Ă��邩�ǂ���
	bool playerBomb;

public:
	const float DODGE_COOLTIME = 2000.0f;
	const float DODGE_MOVETIME = 250.0f;

	const float PLAYER_BOMB_TIME = 1000.0f;
	const int LEVEL_MAX = 10;

	int deviceNum;						// �e�̊Ǘ��ȂǂɎg���ϐ�
	int playerNum;						// �ǂ̃v���C���[���ǂ̃R���g���[���[���g���̂����Ǘ�����
	int levelUpCount;

	std::vector<int> choicePower;		// �p���[�A�b�v�̑I�������i�[
	std::vector<int> choiceStatus;		// �X�e�[�^�X�A�b�v�̑I�������i�[

	BaseCharacter(BulletManager* bullet);	// �R���X�g���N�^
	~BaseCharacter();					// �f�X�g���N�^

	void Rotate(Vector2 stickAngle);
	void Move();
	void Dodge();
	void DodgeCoolTime();
	void LevelUp() {};
	void ObserveExp();
	void LotteryStatus();
	void LotteryPower();
	void ChooseBonus(int selectedButton);

	// �l�̎擾��ύX���s���֐�
	bool GetIsPlayer();
	bool GetIsInvincible();
	int GetExpValue();
	int GetRequestValue();
	void GainExp(int expValue);
	Vector2 GetPlayerPos();
	int GetChooceFlag();
	void SetSurvival();
	void SetPlayerNum(int playerNumber);

	virtual void Proc() = 0;

protected:
	BulletManager* bulletManager;

	Vector2 moveVec;

	int exp;					// �󂵂����̐����Ǘ�

	bool isInvincible;			// ���G���ǂ������f

	Vector2 dodgeVec;

	bool isPlayer;
	bool canDodge;
	bool dodgeNow;				// ������Ă����Ԃ�������
};