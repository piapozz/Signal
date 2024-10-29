#pragma once
#include "../header/BulletManager.h"
#include "../header/InputManager.h"
#include "../header/Const.h"

class UIManager
{
private:
	InputManager* inputManager;
	BulletManager* bulletManager;

	const int COLOR_BLACK = GetColor(0, 0, 0);

	int deviceMax = 2;

	int deviceCount;

public:
	UIManager();
	~UIManager();

	void Proc();
	void Draw(int playerNum);						
	void StatusList(int statusType);

};

