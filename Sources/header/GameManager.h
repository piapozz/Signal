#pragma once

#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "StageManager.h"
#include "BulletManager.h"
#include "UIManager.h"
#include "InputManager.h"

// �Q�[���̐i�s�N���X

class GameManager
{							
public:

	GameManager();												// �R���X�g���N�^
	~GameManager();												// �f�X�g���N�^

	void Init();												// ������
	void Proc();												// ����
	void Draw();												// �`��

private:

	Player* player;						// �v���C���[
	Enemy* enemy;						// �G�l�~�[
	std::vector<BaseObject*> players;	// �v���C���[�����̉ϒ��z��
	CollisionManager* collisionManager;	// �����蔻��
	StageManager* stageManager;			// �X�e�[�W
	BulletManager* bulletManager;		// �e
	UIManager* uiManager;				// UI
	InputManager* inputManager;			// ����

	int playerMax;

};

