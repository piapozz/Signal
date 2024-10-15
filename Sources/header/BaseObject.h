#pragma once
#include <DxLib.h>
#include "../header/Const.h"

class BaseObject
{
protected:
	struct Status
	{
		Vector2 m_position;		// �ʒu
		float m_life;			// �I�u�W�F�N�g�̗̑�
		float m_shapeSize;		// �`�̑傫��
		float m_angle;			// ����
	};

	Status status;

	enum Shape				// �����蔻��̌`��ʂ��邽�߂̏��
	{
		CIRCLE,
		SQUARE,
	};

	int objectModel;		// �I�u�W�F�N�g�̃��f���Ǘ�

	bool canMove;			// �����邩�ǂ������Ǘ�

	bool canHit;			// �ǂ�e�Ȃǃ_���[�W���K�v������̂������

	BaseObject();
	~BaseObject();

	void Draw();

	void SetPosition(VECTOR objectPos);
	void SetModelData(int model);
};
