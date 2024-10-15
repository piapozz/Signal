#pragma once

#include <vector>
#include "BaseBullet.h"

#include "NormalShot.h"

using namespace std;

class BulletManager
{
public:
	// �v���C���[���ƂɎ��e�̏��
	typedef struct BulletPram
	{
		float m_BulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
		int m_BulletType[(int)BulletType::MAX] = { 1,0,0,0,0,0 };
		std::vector<BaseBullet> m_BulletList;
	};

private:

	std::vector<BulletPram> _bulletPram;

	float m_Rate = 1.0f;	// ���ˊԊu

public:


	// �R���X�g���N�^
	BulletManager();
	BulletManager(int playerNum);

	// �f�X�g���N�^
	~BulletManager();

	// �e�̈ړ�
	void Move();

	// �`��
	void Draw();

	// ����
	void AddBullet(int playerNum , BaseObject::Status status);

	// �o���b�g�̃X�e�[�^�X���グ��
	// ���� �グ��X�e�[�^�X�A�v���C���[�̔ԍ��A
	void LevelUpStatus(BulletStatus status , int playerNum);

	// �o���b�g�̃^�C�v���グ��
	// ���� �ǉ�����^�C�v�A�v���C���[�̔ԍ��A
	void LevelUpType(BulletType type, int playerNum);
};