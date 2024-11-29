#pragma once
#include "../header/BaseCharacter.h"

class Player : public BaseCharacter
{
private:
	InputManager* inputManager;

public:
	// コントローラーの状態を管理する
	struct Controller
	{
		Vector2 m_RStick;
		Vector2 m_LStick;
		bool m_LTrigger;
		bool m_RTrigger;
	};

	Controller controller;

	Player(Vector2 pos, BulletManager* bullet) : BaseCharacter(bullet)
	{
		status.m_position = pos;
		status.m_nextPosition = pos;

		// プレイヤーの生存状況
		canMove = true;

		isPlayer = true;


	}

	~Player();								// デストラクタ

	void Proc();
	void Init(BulletManager* bullet, InputManager* input);
	void GetController();
	int InputButtonToInt();
};