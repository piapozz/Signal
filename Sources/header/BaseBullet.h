#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"
#include "BaseObject.h"
#include "Const.h"

class BaseBullet
	: public BaseObject
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

public:

	// �R���X�g���N�^
	BaseBullet();
	BaseBullet(float bulletStatus[], Status objStatus);

	// �f�X�g���N�^
	~BaseBullet();

	// �`��֐�
	void Draw();

	// �˒��Ǘ��֐�
	void CheckRange();

	// ���W�X�V�֐�
	void Move() {};

	// ���e�֐�
	void Impact() {};

	// �j��֐�
	void Destroy() {};

	// �L�����ǂ����Ԃ�
	bool CheckActive() { return _status.m_Flag; }
};