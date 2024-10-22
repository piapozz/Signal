#pragma once
#include "../header/BaseCharacter.h"

class Player : public BaseCharacter
{
private:
	int playerNum;
	
	// コントローラーの状態を管理する
	struct Controller
	{
		Vector2 m_RStick;
		Vector2 m_LStick;
		bool m_LTrigger;
	};

	Controller controller;

	bool isDead;

public:
	Player();								// コンストラクタ
	~Player();								// デストラクタ

	void Proc();
	void SetPlayerNum(int playerNumber);
	void GetController();
};