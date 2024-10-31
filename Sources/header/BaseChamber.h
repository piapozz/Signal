#pragma once

#include "BaseObject.h"

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
{
public:

	// ��b�X�e�[�^�X
	typedef struct MainContainer
	{
		bool m_Flag = false;    // ���˃t���O
		float m_Speed = 3.0f;   // �X�s�[�h
		float m_Power = 0.2f;	// �j���	
		float m_Range = 300.0f;	// �˒�
		int color = GetColor(0, 0, 0);	// �e�ۂ̐F
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

protected:
		
	BaseObject::Status* status;
	MainContainer* mainContainer;

public:


	// �R���X�g���N�^
	BaseChamber();
	BaseChamber(BaseObject::Status *status, MainContainer *container);

	// �f�X�g���N�^
	~BaseChamber();

	// �p�x�C���֐�
	virtual void AngleModifying() = 0;
	
	// �ړ��֐�
	virtual void Move() = 0;

	// ���e�֐�
	virtual void Impact() = 0;

	// ���Ŋ֐� 
	virtual void Destroy() = 0;
	
};