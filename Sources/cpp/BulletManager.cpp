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

		for (int j = 0; j < BULLET_MAX; j++) 
		{
			_bulletPram[i].m_BulletList.push_back(new MainBullet());
		}
	}

	time = GetNowCount();
}

// �f�X�g���N�^
BulletManager::~BulletManager()
{
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < BULLET_MAX; j++)
		{
			delete _bulletPram[i].m_BulletList[j];
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
			if (!_bulletPram[i].m_BulletList[j]->GetActive()) return;

			// �ړ�
			_bulletPram[i].m_BulletList[j]->Move();
		}
	}
}

// �`��
void BulletManager::Draw()
{
	// �v���C���[�Ƃ��ꂼ��̒e�̕��J��Ԃ��Ĉړ�����
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// �L������
			if (!_bulletPram[i].m_BulletList[j]->GetActive()) return;

			// �`��
			_bulletPram[i].m_BulletList[j]->Draw();
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

	float interval = 1 + (_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::RATE] * RATE_VALUE);

	if (GetNowCount() - time < interval) return;

	time = GetNowCount();

	// �g�U�̃p�����[�^�[���������ꍇ���������Ɍ����Ĕ��˂���
	if (_bulletPram[playerNum].m_BulletType[(int)BulletType::MULTI_SHOT] == 0)
	{
		// �n���ꂽ�v���C���[�̒e����ǉ�
		//_bulletPram[playerNum].m_BulletList.push_back(NormalChamber(_bulletPram[playerNum].m_BulletStatus, status));
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
		float rate = _diffusionAngleMax / ((_diffusion * level) + 1);

		// ���W�A���ɕϊ�
		float radianAngle = rate / 180 * DX_PI;

		// ���˃X�e�[�^�X���쐬
		BaseObject::Status temp = status;
		temp.m_angle -= radianAngle * ((_diffusion * level) / 2);

		// ���ꂼ��̊p�x�ɑ΂��Ēe�𔭎�
		for (int i = 0; i < ((_diffusion * level) + 1); i++) 
		{
			temp.m_angle += radianAngle * i;

			// �e��ǉ�
			//_bulletPram[playerNum].m_BulletList.push_back(NormalChamber(_bulletPram[playerNum].m_BulletStatus, temp));

			for (int i = 0; i < _bulletPram[playerNum].m_BulletList.size(); i++)
			{
				if (!_bulletPram[playerNum].m_BulletList[i]->GetActive()) continue;

				// �g����e��������
				_bulletPram[playerNum].m_BulletList[i]->Reload(status, _bulletPram[playerNum].m_BulletStatus, _bulletPram[playerNum].m_BulletType);

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