#pragma once

#include "NormalChamber..h"
#include "ExplosionChamber..h"
#include "MultipleChamber..h"
#include "PenetrationChamber..h"
#include "TrackingChamber..h"
#include "ReflectionChamber..h"

// ���ꂼ��̊֐����Ăяo���Ĉړ��Ȃǂ�����

class MainBullet
{
private:

	// �e�ۂ̐F
	const int _BULLET_COLOR = GetColor(0, 0, 0);

	typedef struct ShotStatus
	{
		
	};

protected:

	ShotStatus _status;

	int graph = LoadGraph("char* FileName");

	float distance = 0;

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

	// �`��
	void Draw();
};