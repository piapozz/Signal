#include "../header/BulletManager.h"

// �R���X�g���N�^
BulletManager::BulletManager() 
{

}

// �R���X�g���N�^
BulletManager::BulletManager(int playerNum)
{
	for (int i = 0; i < playerNum; i++) 
	{
		_bulletPram.push_back(BulletPram());
		_bulletPram[i].time = GetNowCount();

		for (int j = 0; j < BULLET_MAX; j++) 
		{
			_bulletPram[i].m_BulletList.push_back(new MainBullet());
			_bulletPram[i].m_ExplosionList.push_back(new Explosion());
			_bulletPram[i].m_BulletList[j]->SetActive(false);
			_bulletPram[i].m_ExplosionList[j]->SetActive(false);
		}
	}
}

// �f�X�g���N�^
BulletManager::~BulletManager()
{
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < BULLET_MAX; j++)
		{
			delete _bulletPram[i].m_BulletList[j];
			delete _bulletPram[i].m_ExplosionList[j];
		}
	}
}

// �e�̈ړ�
void BulletManager::Move() 
{
	// �v���C���[�Ƃ��ꂼ��̒e�̕��J��Ԃ��Ĉړ�����
	for (int i = 0; i < _bulletPram.size(); i++) 
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++) 
		{
			// �L������
			// �ړ�
			if (_bulletPram[i].m_BulletList[j]->GetActive())
			{
				_bulletPram[i].m_BulletList[j]->UpdateAngle();
				_bulletPram[i].m_BulletList[j]->Move();
			}

			// �������̈ړ��A�g�k
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->Move();
		}
	}
}

// �`��
void BulletManager::Draw()
{
	int count = 0;
	int countE = 0;

	// �v���C���[�Ƃ��ꂼ��̒e�̕��J��Ԃ��Ĉړ�����
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// �L������
			// �`��
			if (_bulletPram[i].m_BulletList[j]->GetActive())
				_bulletPram[i].m_BulletList[j]->Draw();

			// �������̕`��
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->Draw();

			if (_bulletPram[i].m_BulletList[j]->GetActive())
				count++;
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				countE++;
		}
	}

	printfDx("\n%d / %d\n", count , BULLET_MAX * _bulletPram.size());
	printfDx("\n%d / %d\n", countE, BULLET_MAX * _bulletPram.size());
}

// ���W�X�V
void BulletManager::UpdatePosition()
{
	// �v���C���[�Ƃ��ꂼ��̒e�̕��J��Ԃ��č��W�X�V����
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// �������̌o�ߎ��ԃ`�F�b�N
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->CheckExplosionTimeOver();

			// �L������
			if (!_bulletPram[i].m_BulletList[j]->GetActive()) continue;

			// �˒��Ǘ�
			_bulletPram[i].m_BulletList[j]->CheckRange();

			// �X�V
			_bulletPram[i].m_BulletList[j]->UpdatePosition();
		}
	}
}

// // �����̗v��������Ȃ琶������
void BulletManager::CreateExplosion()
{
	// �v���C���[�Ƃ��ꂼ��̒e�̕��J��Ԃ��č��W�X�V����
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// �v������
			if (!_bulletPram[i].m_BulletList[j]->GetExplosion()) continue;

			// ����
			for (int k = 0; k < _bulletPram[i].m_ExplosionList.size(); k++)
			{
				if (_bulletPram[i].m_ExplosionList[k]->GetActive()) continue;

				// �g����e��������
				_bulletPram[i].m_ExplosionList[k] = new Explosion(_bulletPram[i].m_BulletList[j]->GetExplosionStatus(), _bulletPram[i].m_BulletList[j]->status);

				break;
			}
		}
	}
}

/// <summary>
/// �o���b�g���X�g�Ɍ��݂̃X�e�[�^�X�̒e��ǉ�����
/// </summary>
/// <param name="playerNum">�v���C���[�ԍ�</param>
/// <param name="status">�e�𔭎˂�����W�Ɗp�x</param>
void BulletManager::AddBullet(int playerNum , BaseObject::Status status)
{
	// Rate�v�Z

	float interval = 1000 - (_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::RATE] * RATE_VALUE);

	if (GetNowCount() - _bulletPram[playerNum].time < interval) return;

	_bulletPram[playerNum].time = (float)GetNowCount();

	// �g�U�̃p�����[�^�[���������ꍇ���������Ɍ����Ĕ��˂���
	if (_bulletPram[playerNum].m_BulletType[(int)BulletType::MULTI_SHOT] == 0)
	{
		// �n���ꂽ�v���C���[�̒e����ǉ�
		for (int i = 0; i < _bulletPram[playerNum].m_BulletList.size(); i++) 
		{
			if (_bulletPram[playerNum].m_BulletList[i]->GetActive()) continue;

			// �g����e��������
			_bulletPram[playerNum].m_BulletList[i]->Reload(status, _bulletPram[playerNum].m_BulletStatus, _bulletPram[playerNum].m_BulletType);

			break;
		}
	}
	else 
	{
		// ���x�����i�[
		int level = _bulletPram[playerNum].m_BulletType[(int)BulletType::MULTI_SHOT];

		// �Ԋu���Z�o
		float rate = (float)(_diffusionAngleMax / ((_diffusion * level) + 1));

		// ���W�A���ɕϊ�
		float radianAngle = rate;

		// ���˃X�e�[�^�X���쐬
		BaseObject::Status temp = status;
		temp.m_angle -= radianAngle * ((_diffusion * level) / 2);

		// ���ꂼ��̊p�x�ɑ΂��Ēe�𔭎�
		for (int i = 0; i < ((_diffusion * level) + 1); i++)
		{
			// ���݂̊p�x�ɉ����Ēe�̔��˃X�e�[�^�X�𒲐�
			temp.m_angle = status.m_angle - radianAngle * ((_diffusion * level) / 2) + radianAngle * i;

			// �g����e��T���ă����[�h
			for (int j = 0; j < _bulletPram[playerNum].m_BulletList.size(); j++)
			{
				if (_bulletPram[playerNum].m_BulletList[j]->GetActive()) continue;
				
				// �g����e��������
				_bulletPram[playerNum].m_BulletList[j]->Reload(temp, _bulletPram[playerNum].m_BulletStatus, _bulletPram[playerNum].m_BulletType);
				break;
			}
		}
	}
}

// �o���b�g�̃X�e�[�^�X���グ��
// ���� �グ��X�e�[�^�X�A�v���C���[�̔ԍ��A
void BulletManager::LevelUpStatus(BulletStatus status, int playerNum)
{
	// �󂯎�����p�����[�^�[���㏸
	_bulletPram[playerNum].m_BulletStatus[(int)status]++;
}

// �o���b�g�̃^�C�v���グ��
// ���� �ǉ�����^�C�v�A�v���C���[�̔ԍ��A
void BulletManager::LevelUpType(BulletType type, int playerNum)
{
	// �󂯎�����^�C�v���㏸
	_bulletPram[playerNum].m_BulletType[(int)type]++;
}