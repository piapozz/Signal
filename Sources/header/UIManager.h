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
	std::vector<BaseCharacter*> devices;	// �v���C���[�����̉ϒ��z��
	std::vector <StatusUI*> statusUI;

	Vector2 initPos[PLAYER_MAX];

	// �p���[�A�b�v�Ɏg���摜���Ǘ�
	int bulletIcon[(int)BulletType::MAX];
	// �X�e�[�^�X�A�b�v�Ɏg���摜���Ǘ�
	int statusIcon[(int)BulletStatus::MAX];

	int flagStatus;

public:
	UIManager();
	~UIManager();

	void Init(BulletManager* bulletManager, std::vector<BaseCharacter*> devicesObject);
	void Proc();
	void Draw();
};

