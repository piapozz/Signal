#include "../header/GameManager.h"

// �R���X�g���N�^
GameManager::GameManager(InputManager* pInputManager)
{
	collisionManager = new CollisionManager();
	stageManager = new StageManager(collisionManager);
	players.push_back(new Player(stageManager->GetStartPos()[0], bulletManager));
	players.push_back(new Player(stageManager->GetStartPos()[1], bulletManager));
	// enemys.push_back(new Enemy(stageManager->GetStartPos()[1], bulletManager));
	uiManager = new UIManager();
	inputManager = pInputManager;
	// �e��l�����p��
	bulletManager = new BulletManager(players.size() + enemys.size());

	AudioManager::GetInstance().PlayLoopBGM(BGMName::IN_GAME);

	// �Q�[�����I�����Ă��邩���Ǘ�
	isFinish = false;
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
		players[i]->Init(bulletManager, inputManager);
		devices.push_back(players[i]);
	}

	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->Init(bulletManager, devices, collisionManager, stageManager);
		devices.push_back(enemys[i]);
	}

	collisionManager->Init(devices, stageManager->GetBoxData(), bulletManager);

	// �v���C���[�̐����擾
	playerMax = devices.size();
	
	// �v���C���[�̐ݒ�
	for (int i = 0; i < devices.size(); i++)
	{
		BaseCharacter* device = devices[i];
		// �f�o�C�X���Ƃɔԍ�������
		device->deviceNum = i;

		// �v���C���[��������ǂ̃R���g���[���[���g���������蓖�Ă�
		if (device->GetIsPlayer() == true)
		{
			// ���蓖��
			device->SetPlayerNum(i);
			// �v���C���[�p�̃C���[�W��ݒ�
			device->SetImageData("Resources/Signal_Player.png");
		}
		else
		{
			// �G�p�̃C���[�W��ݒ�
			device->SetImageData("Resources/Signal_Enemy.png");
		}
	}

	uiManager->Init(bulletManager, devices);
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

	// �����̐���
	bulletManager->CreateExplosion();

	// �����蔻��
	collisionManager->HitCheck_Everything();
	collisionManager->UpdateHitObj();

	// ���W���X�V
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->UpdatePosition();
	}

	// �e�̍��W�X�V
	bulletManager->UpdatePosition();

	stageManager->Proc();

	// �I���m�F
	CheckFinish();
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

		uiManager->Draw();
	}

	// �e�̕`��
	bulletManager->Draw();
}

// �I���m�F
void GameManager::CheckFinish()
{
	// ���S�m�F
	std::vector<int> activeDevice;
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->SetSurvival();
		if (devices[i]->GetActive())
			activeDevice.push_back(i);
	}
	// �A�N�e�B�u�ȃL������1�ȉ��Ȃ�
	if (activeDevice.size() <= 1)
	{
		winDevice = activeDevice[0];
		isFinish = true;
	}
}

bool GameManager::GetFinish()
{
	return isFinish;
}