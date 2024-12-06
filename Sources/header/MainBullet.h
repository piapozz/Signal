#pragma once

#include "BaseDamageObject.h"
#include "NormalChamber.h"
#include "ExplosionChamber.h"
#include "PenetrationChamber.h"
#include "TrackingChamber.h"
#include "ReflectionChamber.h"
#include "Box.h"

// ���ꂼ��̊֐����Ăяo���Ĉړ��Ȃǂ�����

class MainBullet
	: public BaseDamageObject
{
private:

	BaseChamber::BulletContainer* _bulletContainer = new BaseChamber::BulletContainer();

	float _distance = 0;

	BaseChamber* _chambers[(int)BulletType::MAX];

	float _bulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
	int _bulletType[(int)BulletType::MAX] = { 1,0,0,0,0 };

	void UpdateStatus();

public:

	MainBullet(const int &handle);
	~MainBullet();

	// �p�x�C��
	void UpdateAngle();

	// �ړ�
	void Move();

	// ���e��
	void Impact(const ObjectType &hitType);

	// ���Ŏ�
	void Destroy();

	// �˒��Ǘ��֐�
	void CheckRange();

	// ���W�A�p�x�A�X�e�[�^�X�Z�b�g
	void Reload(const Status &objStatus,const float Pram[],const int type[]);

	// �e�̐������擾
	inline int GetBulletType(const BulletType &type) const { return _bulletType[(int)type]; }

	// �������L�����ǂ���
	inline bool GetExplosion() const
	{
		if (_bulletContainer->explosionContainer->active)
		{
			_bulletContainer->explosionContainer->active = false;
			return true;
		}
		return  false;
	}

	inline BaseChamber::ExplosionContainer GetExplosionStatus() const { return *_bulletContainer->explosionContainer; }
};