#include "../header/GameManager.h"

// �R���X�g���N�^
GameManager::GameManager()
{
	players.push_back(new Player(Vector2(50.0f, 50.0f)));
	players.push_back(new Enemy(Vector2(50.0f, 200.0f)));
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
	
	for (int i = 0; i < players.size(); i++)
	{
		//if (players[i]->GetIsPlayer() == true)
		{
			players[i]->SetPlayerNum(i);
		}
	}

	// �e��l�����p��
	bulletManager = new BulletManager(playerMax);

}
// ����
void GameManager::Proc()
{
	// ���͎擾
	inputManager->Proc();

	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Proc(bulletManager, inputManager);
	}

	// �e�̈ړ�
	bulletManager->Move();

	// �����蔻��
	collisionManager->HitCheck_Everything(players, stageManager->GetBoxData(),bulletManager);
}

// �`��
void GameManager::Draw()
{
	// �X�e�[�W�̕`��
	stageManager->Draw();

	// �v���C���[�����̕`��
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Draw();

		uiManager->Draw(i, bulletManager);
	}

	// �e�̕`��
	bulletManager->Draw();

}


