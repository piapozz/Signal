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
		float time = 1;						// ��������
	public:
		void LevelUp(int level)
		{
			expansionRange = level * 0.2f;
		}

	};

	// �e�̍\����
	struct BulletContainer
	{
		MainContainer mainContainer;
		ReflectionContainer reflectionContainer;
		TrackingContainer trackingContainer;
		PenetrationContainer penetrationContainer;
		ExplosionContainer explosionContainer;
		int level[(int)BulletType::MAX];

	public:
		void LevelUp(int type[])
		{
			int temp[(int)BulletType::MAX];

			for (int i = 0; i < (int)BulletType::MAX; i++) 
			{
				temp[i] = type[i];
			}

			if (temp[(int)BulletType::REFLECTION] > 0) reflectionContainer.LevelUp(temp[(int)BulletType::REFLECTION]);
			if (temp[(int)BulletType::TRACKING_SHOT] > 0) trackingContainer.LevelUp(temp[(int)BulletType::TRACKING_SHOT]);
			if (temp[(int)BulletType::PENETRATION] > 0) penetrationContainer.LevelUp(temp[(int)BulletType::PENETRATION]);
			if (temp[(int)BulletType::EXPLOSION] > 0) explosionContainer.LevelUp(temp[(int)BulletType::EXPLOSION]);
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