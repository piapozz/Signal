#include "../header/GameManager.h"

// �R���X�g���N�^
GameManager::GameManager()
{
	players.push_back(new Player());
	players.push_back(new Enemy());
	collisionManager = new CollisionManager();
	stageManager = new StageManager();
	//bulletManager = new BulletManager();
	uiManager = new UIManager();
	inputManager = new InputManager();
}

// �f�X�g���N�^
GameManager::~GameManager() 
{
	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}
	delete collisionManager;	// �����蔻��
	delete stageManager;		// �X�e�[�W
	delete bulletManager;		// �e
	delete uiManager;			// UI
	delete inputManager;		// ����
}

// ������
void GameManager::Init() 
{
	// �v���C���[�̐����擾
	playerMax = players.size();

	// �e��l�����p��
	bulletManager = new BulletManager(playerMax);

}


// ����
void GameManager::Proc()
{
	// ���͎擾
	inputManager->Proc();

	// �ړ�
	for (int i = 0; i < players.size(); i++)
	{
		
	}

	// �e�̈ړ�
	bulletManager->Move();

	// �����蔻��
	collisionManager->HitCheck_Everything(players, stageManager->GetBoxData());
}

// �`��
void GameManager::Draw()
{
	// �v���C���[�����̕`��
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Draw();
	}

	// �e�̕`��
	bulletManager->Draw();

	// �X�e�[�W�̕`��
	stageManager->Draw();
}


