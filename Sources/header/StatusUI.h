#pragma once
#include "../header/BulletManager.h"
#include "../header/Const.h"
#include <string>

class StatusUI
{
private:

	BulletManager* bullet;

	// 色データ
	const int COLOR_BLACK = GetColor(0, 0, 0);
	const int COLOR_WHITE = GetColor(255, 255, 255);

	const int TEXT_TO_STAR = 10;
	const int STAR_TO_STAR = 20;

	Vector2 infoPos;

	int deviceMax = 2;
	int deviceCount;

	const float DISTANCE_ERROR = 20.0f;

	// パワーアップに使う画像を管理
	int bulletIcon[(int)BulletType::MAX];
	string bulletStateText[(int)BulletStatus::MAX];

public:
	StatusUI(BulletManager* bulletManager);
	~StatusUI();
	void Init();

	void ArrangeIcon();
	void PlayerAround(std::vector<int> vectorArray, Vector2 playerPos);
	void StatusViewer(int deviceNum);

	void LevelUpUI();
};

