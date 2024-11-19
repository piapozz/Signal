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

	// ����
	enum Cardinal
	{
		NORTH = 0,
		EAST,
		SOUTH,
		WEST
	};

	const float distanceError = 20.0f;

	// �p���[�A�b�v�Ɏg���摜���Ǘ�
	int powerImage[(int)BulletType::MAX];
	// �X�e�[�^�X�A�b�v�Ɏg���摜���Ǘ�
	int statusImage[(int)BulletStatus::MAX];

public:
	UIManager();
	~UIManager();

	void Init(BulletManager* bullet);
	void Proc();
	void Draw(int playerNum);
	void PlayerAround(std::vector<int> vectorArray, Vector2 playerPos);
	void StatusViewer(int deviceNum);

	void LevelUpUI();
};

