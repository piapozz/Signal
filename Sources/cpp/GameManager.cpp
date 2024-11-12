#include "../header/GameManager.h"

// �R���X�g���N�^
GameManager::GameManager()
{
	stageManager = new StageManager();
	players.push_back(new Player(stageManager->GetStartPos()[0]));
	players.push_back(new Enemy(stageManager->GetStartPos()[1]));
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
	// 
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Init(bulletManager, inputManager, players, collisionManager);
	}

	collisionManager->Init(players, stageManager->GetBoxData(), bulletManager);

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
		// ���x���A�b�v�ɕK�v�Ȍ��𖞂����Ă�����
		if (players[i]->GetExpValue() >= players[i]->request)
		{

			// ���x���A�b�v�����玟�̃��x���A�b�v�ɕK�v�ȃR�X�g���グ��
			players[i]->request += 3;

			// �O�̔{���񂱂�܂łɃ��x���A�b�v���Ă�����p���[�A�b�v����I��
			if (players[i]->levelUpCount % 3)
			{
				// �p���[�A�b�v�ł���񐔂��ꂠ����


			}

			// �O�̔{����ł͂Ȃ�������X�e�[�^�X����I��
			else 
			{
				// �X�e�[�^�X�A�b�v�ł���񐔂��ꂠ����


			}

		}

		// ���x���A�b�v�ł���񐔂����ăR���g���[���[�̓��͂��󂯎�茋�ʂ𔽉f������
		// �p���[�A�b�v���s��
		if (players[i]->powerUpCount)
		{
			// �񋓑�BulletType�̑傫�����g���ė������擾 
			GetRand((int)BulletType::MAX);


		}

		// �X�e�[�^�X�A�b�v���s��
		else if (players[i]->statusUpCount)
		{

			GetRand((int)BulletStatus::MAX);

		}
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

		uiManager->Draw(i, bulletManager);
	}

	

	// �e�̕`��
	bulletManager->Draw();

}


