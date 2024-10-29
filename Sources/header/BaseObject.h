#pragma once
#include <DxLib.h>
#include "../header/Const.h"

class BaseObject
{
public:
	struct Status
	{
		Vector2 m_position;		// �ʒu
		float m_angle;			// ����
		float m_life;			// �I�u�W�F�N�g�̗̑�
		float m_shapeSize;		// �`�̑傫��
		Shape m_shape;			// �`

		// �X�e�[�^�X�̏�����
		Status() 
		{
			m_position.x = 0.0f;
			m_position.y = 0.0f;
			m_angle = 0.0;
			m_life = 1.0f;
			m_shapeSize = 1.0;
		}
	};

	Status GetStatus();			// �\���̂̏����擾

	Vector2 oldPosition;

	BaseObject();							// �R���X�g���N�^
	~BaseObject();							// �f�X�g���N�^

	Shape GetShape();						// �`���擾

protected:
	Status status;

	int objectHandle;		// �I�u�W�F�N�g�̌����ڂ��Ǘ��i���f����摜�j

	bool canMove;			// �����邩�ǂ������Ǘ�
	bool canHit;			// �ǂ�e�Ȃǃ_���[�W���K�v������̂������
	bool hitObject;			// �I�u�W�F�N�g�Ƀq�b�g���������Ǘ�
	bool hitBullet;			// �e�Ƀq�b�g���������Ǘ�

	void Draw();
	void TakeDamage(float damageSize);

	void SetPosition(Vector2 objectPos);
	void SetLife(float life);
	void SetAngle(float angle);
	void SetShapeSize(float size);
	void SetModelData(int model);
};
