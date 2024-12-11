#pragma once

#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "StageManager.h"
#include "BulletManager.h"
#include "UIManager.h"
#include "InputManager.h"
#include "Memory.h"
#include "AudioManager.h"

// �Q�[���̐i�s�N���X

class GameManager
{
public:

	GameManager(InputManager* pInputManager) :_pInputManager(pInputManager), _pCollisionManager(new CollisionManager()),
		_pStageManager(new StageManager(_pCollisionManager)), _pUiManager(new UIManager()), _pBulletManager(new BulletManager(PLAYER_MAX)) {};				// �R���X�g���N�^
	~GameManager();												// �f�X�g���N�^

	void Init();												// ������
	void Proc();												// ����
	void Draw();												// �`��

	bool GetFinish();

	static int winDevice;

private:

	std::vector<BaseCharacter*> _pDevices;	// �v���C���[�����̉ϒ��z��
	std::vector<Player*> _pPlayers;			// �v���C���[�̔z��
	std::vector<Enemy*> _pEnemys;			// �G�̔z��
	CollisionManager* _pCollisionManager;	// �����蔻��
	StageManager* _pStageManager;			// �X�e�[�W
	BulletManager* _pBulletManager;			// �e
	UIManager* _pUiManager;					// UI
	InputManager* _pInputManager;			// ����

	bool _isFinish;

	void CheckFinish();
};

