#pragma once
#include "../header/BaseCharacter.h"

class Player : public BaseCharacter
{
private:
	int playerNum;
	
	// �R���g���[���[�̏�Ԃ��Ǘ�����
	struct Controller
	{
		Vector2 m_RStick;
		Vector2 m_LStick;
		bool m_LTrigger;
	};

	Controller controller;

	bool isDead;

public:
	Player();
	~Player();

	void Proc();
	void SetPlayerNum(int playerNumber);
	void GetController();
};