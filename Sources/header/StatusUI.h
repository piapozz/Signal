#pragma once
#include "../header/BulletManager.h"
#include "../header/Const.h"
#include <string>

class StatusUI
{
private:

	BulletManager* bullet;

	Vector2 initPos;

	int deviceMax = 2;
	int deviceCount;

	// ’e‚ÌƒŒƒxƒ‹•\Ž¦‚ÉŽg‚¤‰æ‘œ
	int levelViewIcon;
	string bulletStateText[(int)BulletStatus::MAX];
	int statusDiaIcon[1];

public:
	StatusUI(BulletManager* bulletManager, Vector2 position);
	~StatusUI();
	void Init();

	void ArrangeIcon(int deviceNum, int imageHandle[]);
	void PlayerAround(std::vector<int> vectorArray, Vector2 playerPos, int imageHandle[]);
	void StatusViewer(int deviceNum);
	void PlayerLevel(int playerLevel);
	void RequestCount(int exp, int request);

	void LevelUpUI();
};

