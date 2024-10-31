#pragma once
#include <DxLib.h>
#include "../header/Const.h"

class BaseObject
{
public:
	struct Status
	{
		Vector2 m_position;		// �ʒu
		Vector2 m_nextPosition;	// �ړ��\����W
		float m_angle;			// ����
		float m_life;			// �I�u�W�F�N�g�̗̑�
		float m_shapeSize;		// �`�̑傫��
		Shape m_shape;			// �`

		// �X�e�[�^�X�̏�����
		Status()
		{
			m_position.x = 0.0f;
			m_position.y = 0.0f;
			m_nextPosition.x = 0.0f;
			m_nextPosition.y = 0.0f;
			m_angle = 0.0;
			m_life = 1.0f;
			m_shapeSize = 5.0f;
		}
	};

	Status GetStatus();			// �\���̂̏����擾

	BaseObject();							// �R���X�g���N�^
	~BaseObject();							// �f�X�g���N�^

	void TakeDamage(float damageSize);
	void SetHitFlag(bool hitCheck);
	virtual void Move(Vector2 moveVec);
	void UpdatePosition();

	void SetPosition(Vector2 objectPos);
	void SetLife(float life);
	void SetAngle(float angle);
	void SetShapeSize(float size);
	void SetModelData(int model);
	void Draw();

	Shape GetShape();						// �`���擾

protected:
	Status status;

	int objectHandle;		// �I�u�W�F�N�g�̌����ڂ��Ǘ��i���f����摜�j

	bool canMove;			// �����邩�ǂ������Ǘ�
	bool hitObject;			// �I�u�W�F�N�g�Ƀq�b�g���������Ǘ�
};
