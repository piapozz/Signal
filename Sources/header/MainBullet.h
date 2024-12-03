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

	MainBullet(int handle);
	~MainBullet();

	// �p�x�C��
	void UpdateAngle();

	// �ړ�
	void Move();

	// ���e��
	void Impact(ObjectType hitType);

	// ���Ŏ�
	void Destroy();

	// �˒��Ǘ��֐�
	void CheckRange();

	// ���W�A�p�x�A�X�e�[�^�X�Z�b�g
	void Reload(Status objStatus, float Pram[], int type[]);

	// �e�̐������擾
	int GetBulletType(BulletType type) { return _bulletType[(int)type]; }

	// �������L�����ǂ���
	bool GetExplosion() 
	{
		if (_bulletContainer->explosionContainer->active)
		{
			_bulletContainer->explosionContainer->active = false;
			return true;
		}
		return  false;
	}

	BaseChamber::ExplosionContainer GetExplosionStatus() { return *_bulletContainer->explosionContainer; }
};