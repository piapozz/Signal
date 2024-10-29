#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"
#include "BaseObject.h"
#include "Const.h"

// �@ �o���b�g�X�e�[�^�X�\���̂������������z�֐��̗p��
// �X�e�[�^�X�A�摜�̉����֐�
// �p�x�C���֐�
// �ړ��֐�
// ���e�֐�
// ���Ŋ֐�
// �A ���x���ɉ��������ʂ̏㏸�֐����쐬
// �ђʐ�
// �����͈�
// ���ˉ�
// �U���W��
// �B �����ɔ����⏕�֐�

class BaseChamber
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

	float distance = 0;

public:

	// ��b�X�e�[�^�X
	typedef struct MainContainer
	{
		bool m_Flag = false;    // ���˃t���O
		float m_Speed = 5.0f;   // �X�s�[�h
		float m_Power = 1.0f;	// �j���	
		float m_Range = 3.0f;	// �˒�
	};

	// ���˃X�e�[�^�X
	typedef struct ReflectionContainer
	{

	};

	// �U���X�e�[�^�X
	typedef struct TrackingContainer
	{

	};

	// �ђʃX�e�[�^�X
	typedef struct PenetrationContainer
	{

	};

	// �����X�e�[�^�X
	typedef struct ExplosionContainer
	{

	};

	// �e�̍\����
	typedef struct BulletContainer
	{
		MainContainer mainContainer;
		ReflectionContainer reflectionContainer;
		TrackingContainer trackingContainer;
		PenetrationContainer penetrationContainer;
		ExplosionContainer explosionContainer;
	};

	// �R���X�g���N�^
	BaseChamber();
	BaseChamber(float bulletStatus[], Status objStatus);
	BaseChamber(Status status, MainContainer container);

	// �f�X�g���N�^
	~BaseChamber();

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