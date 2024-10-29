#pragma once
#include "../header/BulletManager.h"
#include "../header/Const.h"

class UIManager
{
private:
	BulletManager* bulletManager;

	const int COLOR_BLACK = GetColor(0, 0, 0);

	const int PLAYER_HEIGHT_1 = 20;
	const int PLAYER_WIDTH_1 = 20;

	const int PLAYER_HEIGHT_2 = 1920 - 250;
	const int PLAYER_WIDTH_2 = 20;

	int infoHeight, infoWidth;

	int deviceMax = 2;
	int deviceCount;

public:
	UIManager();
	~UIManager();

	void Proc();
	void Draw(int playerNum);
	void StatusList(int statusType);

};

