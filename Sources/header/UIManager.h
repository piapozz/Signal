#pragma once
#include "../header/BulletManager.h"
#include "../header/BaseCharacter.h"
#include "../header/StatusUI.h"
#include "../header/Const.h"
#include <string>

class UIManager
{
private:

	BulletManager* bullet;
	std::vector<BaseCharacter*> devices;	// プレイヤーたちの可変長配列
	std::vector <StatusUI*> statusUI;

	Vector2 initPos[PLAYER_MAX];

	// パワーアップに使う画像を管理
	int bulletIcon[(int)BulletType::MAX];
	// ステータスアップに使う画像を管理
	int statusIcon[(int)BulletStatus::MAX];

	int flagStatus;

public:
	UIManager();
	~UIManager();

	void Init(BulletManager* bulletManager, std::vector<BaseCharacter*> devicesObject);
	void Proc();
	void Draw();
};

