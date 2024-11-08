#pragma once

#include "NormalChamber.h"
#include "ExplosionChamber.h"
#include "PenetrationChamber.h"
#include "TrackingChamber.h"
#include "ReflectionChamber.h"

// ���ꂼ��̊֐����Ăяo���Ĉړ��Ȃǂ�����

class MainBullet
	: public BaseDamageObject
{
private:

	BaseChamber::BulletContainer _bulletContainer;

	float distance = 0;

	NormalChamber* normalChanber;

	float bulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
	int bulletType[(int)BulletType::MAX] = { 1,0,0,0,0,0 };

	void UpdateStatus();

public:

	MainBullet();
	~MainBullet();

	// �p�x�C��
	void UpdateAngle();

	// �ړ�
	void Move();

	// ���e��
	void Impact();

	// ���Ŏ�
	void Destroy();

	// �˒��Ǘ��֐�
	void CheckRange();

	// ���W�A�p�x�A�X�e�[�^�X�Z�b�g
	void Reload(Status objStatus, float Pram[], int type[]);
};