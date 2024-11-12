#include "../header/GameManager.h"

// �R���X�g���N�^
GameManager::GameManager()
{
	stageManager = new StageManager();
	players.push_back(new Player(stageManager->GetStartPos()[0]));
	enemys.push_back(new Enemy(stageManager->GetStartPos()[1]));
	collisionManager = new CollisionManager();
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
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->Init(collisionManager);
		players.push_back(enemys[i]);
	}

	// 
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Init(bulletManager, inputManager, players);
	}

	collisionManager->Init(players, stageManager->GetBoxData(), bulletManager);

	uiManager->Init(bulletManager);

	// �v���C���[�̐����擾
	playerMax = players.size();
	
	// �v���C���[�̐ݒ�
	for (int i = 0; i < players.size(); i++)
	{
		// �f�o�C�X���Ƃɔԍ�������
		players[i]->deviceNum = i;

		// �v���C���[��������ǂ̃R���g���[���[���g���������蓖�Ă�
		if (players[i]->GetIsPlayer() == true)
		{
			// ���蓖��
			players[i]->SetPlayerNum(i);
			// �v���C���[�p�̃C���[�W��ݒ�
			players[i]->SetImageData("Resources/Player.png");
		}
		else
		{
			// �G�p�̃C���[�W��ݒ�
			players[i]->SetImageData("Resources/Enemy.png");
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
		players[i]->Proc();
	}

	// �e�̈ړ�
	bulletManager->Move();

	// �����蔻��
	collisionManager->HitCheck_Everything();

	// ���W���X�V
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->UpdatePosition();
	}

	// ���x���A�b�v����
	for (int i = 0; i < players.size(); i++)
	{
	
	}

	// �e�̍��W�X�V
	bulletManager->UpdatePosition();

	stageManager->Proc();
}

// �`��
void GameManager::Draw()
{
	// �X�e�[�W�̕`��
	stageManager->Draw();

	// �v���C���[�����̕`��
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->status.m_isActive != false)players[i]->Draw();

		uiManager->Draw(i);
	}

	

	// �e�̕`��
	bulletManager->Draw();

}


