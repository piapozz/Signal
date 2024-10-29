#include "../header/GameManager.h"

// �R���X�g���N�^
GameManager::GameManager()
{
	player = new Player();
	enemy = new Enemy();
	collisionManager = new CollisionManager();
	stageManager = new StageManager();
	//bulletManager = new BulletManager();
	uiManager = new UIManager();
	inputManager = new InputManager();
}

// �f�X�g���N�^
GameManager::~GameManager() 
{
	delete player;				// �v���C���[
	delete enemy;				// �G�l�~�[
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
	playerMax = inputManager->GetPlayerNum();

	// �e��l�����p��
	bulletManager = new BulletManager(playerMax);

}


// ����
void GameManager::Proc()
{
	// ���͎擾
	inputManager->Proc();

	// �v���C���[�̈ړ�

	// �G�̈ړ�

	// �e�̈ړ�
	bulletManager->Move();

	// �����蔻��
	collisionManager->
}

// �`��
void GameManager::Draw()
{
	bulletManager->Draw();
}


