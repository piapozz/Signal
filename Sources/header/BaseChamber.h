#pragma once

#include "BaseDamageObject.h"
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
{
public:

	// ��b�X�e�[�^�X
	 struct MainContainer
	{
		float m_Speed = 5.0f;			// �X�s�[�h
		float m_Range = 1.0f;			// �˒�
		int color = GetColor(0, 0, 0);	// �e�ۂ̐F
	};

	// ���˃X�e�[�^�X
	struct ReflectionContainer
	{
		int reflectionCount = 0;		// ���ˉ�
		Vector2 norm;					// �@��
	public:
		void LevelUp(int level)
		{
			reflectionCount = level;
		}
	};

	// �U���X�e�[�^�X
	struct TrackingContainer
	{
		float turnAngle = 5;			// �␳����p�x
		Vector2 targetPosition;			// �U���Ώ�
	public:
		void LevelUp(int level)
		{
			turnAngle = (float)(level * 5.0f);
		}
	};

	// �ђʃX�e�[�^�X
	struct PenetrationContainer
	{
		int penetrationCount = 0;		// �ђʉ� 
	public:
		void LevelUp(int level)
		{
			penetrationCount = level;
		}
	};

	// �����X�e�[�^�X
	struct ExplosionContainer
	{
		float expansionRange = 0.2f;			// ��t���[�����Ƃɖc������͈�
		float time = 2;							// ��������
		bool active = false;					// �����̗L����
	public:
		void LevelUp(int level)
		{
			expansionRange = level * 0.2f;
		}

	};

	// �e�̍\����
	struct BulletContainer
	{
		MainContainer* mainContainer = new MainContainer();
		ReflectionContainer* reflectionContainer = new ReflectionContainer();
		TrackingContainer* trackingContainer = new TrackingContainer();
		PenetrationContainer* penetrationContainer = new PenetrationContainer();
		ExplosionContainer* explosionContainer = new ExplosionContainer();
		int level[(int)BulletType::MAX];

	public:
		void LevelUp(int type[])
		{
			int temp[(int)BulletType::MAX];

			for (int i = 0; i < (int)BulletType::MAX; i++) 
			{
				temp[i] = type[i];
			}

			reflectionContainer->LevelUp(temp[(int)BulletType::REFLECTION]);
			trackingContainer->LevelUp(temp[(int)BulletType::TRACKING_SHOT]);
			penetrationContainer->LevelUp(temp[(int)BulletType::PENETRATION]);
			explosionContainer->LevelUp(temp[(int)BulletType::EXPLOSION]);
		}
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
	virtual bool Impact() = 0;

	// ���Ŋ֐� 
	virtual void Destroy() = 0;
	
};