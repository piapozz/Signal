#pragma once
#include "../header/BaseCharacter.h"

class Player : public BaseCharacter
{
private:
	BulletManager* bulletManager;
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

	Player(Vector2 pos);					// コンストラクタ
	~Player();								// デストラクタ

	void Proc();
	void Init(BulletManager* bullet, InputManager* input);
	void GetController();
	int InputButtonToInt();
};