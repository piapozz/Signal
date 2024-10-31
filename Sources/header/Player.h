#pragma once
#include "../header/BaseCharacter.h"

class Player : public BaseCharacter
{
private:
	
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

	bool isDead;

	int playerNum;

	Player(Vector2 pos);					// コンストラクタ
	~Player();								// デストラクタ

	void Proc(BulletManager* bullet, InputManager* inputManager);
	void GetController(InputManager* inputManager);
};