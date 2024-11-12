#pragma once

#include "BaseDamageObject.h"

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
		float m_Speed = 5.0f;   // �X�s�[�h
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
		float turnAngle = 5;			// �␳����p�x
		Vector2 targetPosition;			// �U���Ώ�
	};

	// �ђʃX�e�[�^�X
	typedef struct PenetrationContainer
	{

	};

	// �����X�e�[�^�X
	typedef struct ExplosionContainer
	{
		float expansionRange;			// �c������͈�

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
	BulletContainer* bulletContainer;

public:


	// �R���X�g���N�^
	BaseChamber();
	BaseChamber(BaseObject::Status *status, BulletContainer*container);

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