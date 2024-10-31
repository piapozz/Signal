#pragma once

#include <vector>
#include "MainBullet.h"

using namespace std;

class BulletManager
{
public:
	// �v���C���[���ƂɎ��e�̏��
	typedef struct BulletPram
	{
		float m_BulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
		int m_BulletType[(int)BulletType::MAX] = { 1,0,0,0,0,0 };
		std::vector<MainBullet*> m_BulletList;
	};

	const int BULLET_MAX = 128;

private:

	std::vector<BulletPram> _bulletPram;

	const float RATE_VALUE = 60.2f;	// �ꃌ�x�����Ƃɏオ���Ă������[�g

	int _diffusion = 2;				// �g�U�̃��x���ꂲ�Ƃɑ�����e�̐�
	int _diffusionAngleMax = 120;	// �g�U����p�x
	float time = 0;					// ���݂̕b��

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

	// �e�̍��W�ꊇ�X�V
	void UpdatePosition();

	// ����
	void AddBullet(int playerNum , BaseObject::Status status);

	std::vector<BulletPram> GetBulletList() { return _bulletPram; }

	// �o���b�g�̃X�e�[�^�X���グ��
	// ���� �グ��X�e�[�^�X�A�v���C���[�̔ԍ��A
	void LevelUpStatus(BulletStatus status , int playerNum);

	// �o���b�g�̃^�C�v���グ��
	// ���� �ǉ�����^�C�v�A�v���C���[�̔ԍ��A
	void LevelUpType(BulletType type, int playerNum);
};