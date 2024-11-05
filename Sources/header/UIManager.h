#pragma once
#include "../header/BulletManager.h"
#include "../header/Const.h"

class UIManager
{
private:

	const int COLOR_BLACK = GetColor(0, 0, 0);

	const int PLAYER_HEIGHT_1 = 20;
	const int PLAYER_WIDTH_1 = 20;

	const int PLAYER_HEIGHT_2 = 1920 - 250;
	const int PLAYER_WIDTH_2 = 20;

	int bulletIcon[(int)BulletType::MAX];

	// const char bulletStateText[(int)BulletStatus::MAX];

	int infoHeight, infoWidth;

	int deviceMax = 2;
	int deviceCount;

public:
	UIManager();
	~UIManager();

	void Init();
	void Proc();
	void Draw(int playerNum, BulletManager* bullet);

};

