#pragma once

#include "NormalShot.h"
#include "ExplosionShot.h"
#include "MultipleShot.h"
#include "PenetrationShot.h"
#include "TrackingShot.h"
#include "ReflectionShot.h"

// BaseBullet�|�C���^���R���X�g���N�^��n��
// ���ꂼ��̊֐����Ăяo���Ĉړ��Ȃǂ�����

class MixBullet
{
private:

	// �e�ۂ̐F
	const int _BULLET_COLOR = GetColor(0, 0, 0);

	typedef struct ShotStatus
	{
		bool m_Flag = false;    // ���˃t���O
		float m_Speed = 5.0f;   // �X�s�[�h
		float m_Power = 1.0f;	// �j���	
		float m_Range = 3.0f;	// �˒�
	};

protected:

	ShotStatus _status;

	int graph = LoadGraph("char* FileName");

	float distance = 0;

public:

	MixBullet();
	~MixBullet();

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