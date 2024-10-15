#include "../header/BulletManager.h"

// �R���X�g���N�^
BulletManager::BulletManager() 
{

}


// �R���X�g���N�^
BulletManager::BulletManager(int playerNum)
{

}


// �R���X�g���N�^
BulletManager::~BulletManager()
{

}

// �e�̈ړ�
void BulletManager::Move() 
{
	// �v���C���[�Ƃ��ꂼ��̒e�̕��J��Ԃ��Ĉړ�����
	for (int i = 0; i < bulletPram.size(); i++) 
	{
		for (int j = 0; j < bulletPram[i].m_BulletList.size(); j++) 
		{
			// �ړ�
			bulletPram[i].m_BulletList[j].Move();
		}
	}
}

// �`��
void BulletManager::Draw()
{
	// �v���C���[�Ƃ��ꂼ��̒e�̕��J��Ԃ��Ĉړ�����
	for (int i = 0; i < bulletPram.size(); i++)
	{
		for (int j = 0; j < bulletPram[i].m_BulletList.size(); j++)
		{
			// �`��
			bulletPram[i].m_BulletList[j].Draw();
		}
	}
}

// ����
void BulletManager::AddBullet(int playerNum)
{
	// �n���ꂽ�v���C���[�̒e����ǉ�
	bulletPram[playerNum].m_BulletList.push_back(BaseBullet());
}


// �o���b�g�̃X�e�[�^�X���グ��
// ���� �グ��X�e�[�^�X�A�v���C���[�̔ԍ��A
void BulletManager::LevelUpStatus(BulletStatus status, int playerNum)
{
	// �󂯎�����p�����[�^�[���㏸
	bulletPram[playerNum].m_BulletStatus[status]++;
}

// �o���b�g�̃^�C�v���グ��
// ���� �ǉ�����^�C�v�A�v���C���[�̔ԍ��A
void BulletManager::LevelUpStatus(BulletStatus type, int playerNum)
{
	// �󂯎�����^�C�v���㏸
	bulletPram[playerNum].m_BulletType[type]++;
}