#pragma once
#include "../header/BulletManager.h"
#include "../header/Const.h"
#include <string>

class UIManager
{
private:

	BulletManager* bulletManager;

	const int COLOR_BLACK = GetColor(255, 0, 0);

	int bulletIcon[(int)BulletType::MAX];

	string bulletStateText[(int)BulletStatus::MAX];

	Vector2 infoPos;

	int deviceMax = 2;
	int deviceCount;

public:
	UIManager(Vector2 initPos);
	~UIManager();

	void Init(BulletManager* bullet);
	void Proc();
	void Draw(int playerNum);
	void LevelUpUI();

	void StatusUpUI(std::vector<int> statusNum);
	void PowerUpUI(std::vector<int> typeNum);

};

