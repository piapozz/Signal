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
	// �e��l�����p��
	bulletManager = new BulletManager(players.size() + enemys.size());
}

// �f�X�g���N�^
GameManager::~GameManager() 
{
	for (int i = 0; i < devices.size(); i++)
	{
		delete devices[i];
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
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Init(bulletManager,inputManager);
		devices.push_back(players[i]);
	}

	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->Init(bulletManager, devices, collisionManager, stageManager);
		devices.push_back(enemys[i]);
	}

	collisionManager->Init(devices, stageManager->GetBoxData(), bulletManager);

	uiManager->Init(bulletManager);

	// �v���C���[�̐����擾
	playerMax = devices.size();
	
	// �v���C���[�̐ݒ�
	for (int i = 0; i < devices.size(); i++)
	{
		// �f�o�C�X���Ƃɔԍ�������
		devices[i]->deviceNum = i;

		// �v���C���[��������ǂ̃R���g���[���[���g���������蓖�Ă�
		if (devices[i]->GetIsPlayer() == true)
		{
			// ���蓖��
			devices[i]->SetPlayerNum(i);
			// �v���C���[�p�̃C���[�W��ݒ�
			devices[i]->SetImageData("Resources/Player.png");
		}
		else
		{
			// �G�p�̃C���[�W��ݒ�
			devices[i]->SetImageData("Resources/Enemy.png");
		}
	}


}
// ����
void GameManager::Proc()
{
	// ���͎擾
	inputManager->Proc();

	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->Proc();
	}

	// �e�̈ړ�
	bulletManager->Move();

	// �����蔻��
	collisionManager->HitCheck_Everything();

	// ���W���X�V
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->UpdatePosition();
	}

	// ���x���A�b�v����
	for (int i = 0; i < devices.size(); i++)
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
	for (int i = 0; i < devices.size(); i++)
	{
		if (devices[i]->status.m_isActive != false)devices[i]->Draw();

		uiManager->Draw(i);
	}

	

	// �e�̕`��
	bulletManager->Draw();

}


