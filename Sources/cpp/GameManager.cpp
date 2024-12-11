#include "../header/GameManager.h"

// �f�X�g���N�^
GameManager::~GameManager() 
{
	for (int i = 0; i < _pDevices.size(); i++)
	{
		delete _pDevices[i];
	}
	delete _pCollisionManager;	// �����蔻��
	delete _pStageManager;		// �X�e�[�W
	delete _pBulletManager;		// �e
	delete _pUiManager;			// UI
	delete _pInputManager;		// ����
}

// ������
void GameManager::Init()
{
	_pPlayers.push_back(new Player(_pStageManager->GetStartPos()[0], _pBulletManager));
	_pPlayers.push_back(new Player(_pStageManager->GetStartPos()[1], _pBulletManager));

	AudioManager::GetInstance().PlayLoopBGM(BGMName::IN_GAME);

	// �Q�[�����I�����Ă��邩���Ǘ�
	_isFinish = false;

	for (int i = 0; i < _pPlayers.size(); i++)
	{
		_pPlayers[i]->Init(_pBulletManager, _pInputManager);
		_pDevices.push_back(_pPlayers[i]);
	}

	for (int i = 0; i < _pEnemys.size(); i++)
	{
		_pEnemys[i]->Init(_pBulletManager, _pDevices, _pCollisionManager, _pStageManager);
		_pDevices.push_back(_pEnemys[i]);
	}

	_pCollisionManager->Init(_pDevices, _pStageManager->GetBoxData(), _pBulletManager);
	
	// �v���C���[�̐ݒ�
	for (int i = 0; i < _pDevices.size(); i++)
	{
		BaseCharacter* device = _pDevices[i];
		// �f�o�C�X���Ƃɔԍ�������
		device->deviceNum = i;

		// �v���C���[��������ǂ̃R���g���[���[���g���������蓖�Ă�
		if (device->GetIsPlayer() == true)
		{
			// ���蓖��
			device->SetPlayerNum(i);
			// �v���C���[�p�̃C���[�W��ݒ�
			device->SetImageData(PLAYER_GRAPH_ADRESS[i].c_str());
		}
		//else
		//{
		//	// �G�p�̃C���[�W��ݒ�
		//	device->SetImageData("Resources/Signal_Enemy.png");
		//}
	}

	_pUiManager->Init(_pBulletManager, _pDevices);
}
// ����
void GameManager::Proc()
{
	// ���͎擾
	_pInputManager->Proc();

	for (int i = 0; i < _pDevices.size(); i++)
	{
		_pDevices[i]->Proc();
	}

	// �e�̈ړ�
	_pBulletManager->Move();

	// �����̐���
	_pBulletManager->CreateExplosion();

	// �����蔻��
	_pCollisionManager->HitCheck_Everything();
	_pCollisionManager->UpdateHitObj();

	// ���W���X�V
	for (int i = 0; i < _pDevices.size(); i++)
	{
		_pDevices[i]->UpdatePosition();
	}

	// �e�̍��W�X�V
	_pBulletManager->UpdatePosition();

	_pStageManager->Proc();

	// �I���m�F
	CheckFinish();
}

// �`��
void GameManager::Draw()
{
	// �X�e�[�W�̕`��
	_pStageManager->Draw();

	// �e�̕`��
	_pBulletManager->Draw();

	// �v���C���[�����̕`��
	for (int i = 0; i < _pDevices.size(); i++)
	{
		if (_pDevices[i]->status.m_isActive != false)_pDevices[i]->Draw();

		_pUiManager->Draw();
	}
}

// �I���m�F
void GameManager::CheckFinish()
{
	// ���S�m�F
	std::vector<int> activeDevice;
	for (int i = 0; i < _pDevices.size(); i++)
	{
		// ���S������
		_pDevices[i]->SetSurvival();

		// ���S���Ă��邩�m�F
		if (_pDevices[i]->GetActive())
			// ���S���Ă��Ȃ�������ǉ�
			activeDevice.push_back(i);
	}

	// �A�N�e�B�u�ȃL������1�ȉ��Ȃ�
	if (activeDevice.size() <= 1)
	{
		// �z���0�Ԗڂɂ���v���C���[�����҂ɂ���
		Memory::GetInstance().winner = activeDevice[0] + 1;

		// �Q�[�����I��
		_isFinish = true;
	}
}

bool GameManager::GetFinish()
{
	return _isFinish;
}