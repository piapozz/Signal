#pragma once

#include <vector>
#include "MainBullet.h"
#include "Explosion.h"

using namespace std;

class BulletManager
{
public:
	// �v���C���[���ƂɎ��e�̏��
	struct BulletPram
	{
		float m_BulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
		int m_BulletType[(int)BulletType::MAX] = { 1,0,0,0,0 };
		std::vector<MainBullet*> m_BulletList;
		std::vector<Explosion*> m_ExplosionList;
		float time = 0;
	};


private:

	std::vector<BulletPram> _bulletPram;

	const float RATE_VALUE = 100.0f;	// �ꃌ�x�����Ƃɏオ���Ă������[�g

	const int DIFFUSION = 2;				// �g�U�̃��x���ꂲ�Ƃɑ�����e�̐�
	const int DIFFUSION_ANGLE_MAX = 120;	// �g�U����p�x
	const int BULLET_MAX = 1024;
	const int EXPLOSION_MAX = BULLET_MAX;

public:

	// �R���X�g���N�^
	BulletManager();
	BulletManager(const int &playerNum);

	// �f�X�g���N�^
	~BulletManager();

	// �e�̈ړ�
	void Move();

	// �`��
	void Draw();

	// �e�̍��W�ꊇ�X�V
	void UpdatePosition();

	// �����̗v��������Ȃ琶������
	void CreateExplosion();
	void CreateExplosion(const BaseObject::Status &status, const BaseChamber::ExplosionContainer &container);

	// ����
	void AddBullet(const int &playerNum, const BaseObject::Status &status);

	// �o�b���b�g���X�g���擾
	inline std::vector<BulletPram> GetBulletList() const { return _bulletPram; }

	// �o���b�g�̃X�e�[�^�X���グ��
	// ���� �グ��X�e�[�^�X�A�v���C���[�̔ԍ��A
	void LevelUpStatus(const BulletStatus &status,const int &playerNum);

	// �o���b�g�̃^�C�v���グ��
	// ���� �ǉ�����^�C�v�A�v���C���[�̔ԍ��A
	void LevelUpType(const BulletType &type, const int &playerNum);
};