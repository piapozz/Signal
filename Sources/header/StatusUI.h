#pragma once
#include "../header/BulletManager.h"
#include "../header/Const.h"
#include <string>

class StatusUI
{
private:

	BulletManager* bullet;

	// �F�f�[�^
	const int COLOR_BLACK = GetColor(0, 0, 0);
	const int COLOR_WHITE = GetColor(255, 255, 255);

	const int TEXT_TO_STAR = 10;
	const int STAR_TO_STAR = 20;

	Vector2 initPos;

	int deviceMax = 2;
	int deviceCount;

	const float DISTANCE_ERROR = 50.0f;
	const float LEVEL_BAR_HEIGHT = BULLET_ICON_WIDTH / 2;
	const float LEVEL_BAR_WIDTH = BULLET_ICON_HEIGHT / 2;
	const int LEVEL_MAX = 5;
	
	const float TYPE_ICON_HEIGHT = 50.0f;
	const float TYPE_ICON_WIDTH = 50.0f;

	const Vector2 TYPE_ICON = { TYPE_ICON_HEIGHT / 2 ,TYPE_ICON_WIDTH / 2 };

	// �p���[�A�b�v�Ɏg���摜���Ǘ�
	int bulletIcon[(int)BulletType::MAX];
	// �e�̃��x���\���Ɏg���摜
	int levelViewIcon;
	string bulletStateText[(int)BulletStatus::MAX];

public:
	StatusUI(BulletManager* bulletManager, Vector2 position);
	~StatusUI();
	void Init();

	void ArrangeIcon(int deviceNum);
	void PlayerAround(std::vector<int> vectorArray, Vector2 playerPos);
	void StatusViewer(int deviceNum);

	void LevelUpUI();
};

