#pragma once
#include <DxLib.h>

class BaseObject
{
protected:

	struct Status
	{
		VECTOR m_position;		// �ʒu
		float m_life;			// �I�u�W�F�N�g�̗̑�
		float m_shapeSize;		// �`�̑傫��
		float m_angle;			// ����
		bool m_canHit;			// �ǂ�e�Ȃǃ_���[�W���K�v������̂������
	};

	Status status;

	int objectModel;		// �I�u�W�F�N�g�̃��f���Ǘ�

	enum Shape				// �����蔻��̌`��ʂ��邽�߂̏��
	{
		CIRCLE,
		SQUARE,
	};

	BaseObject();
	~BaseObject();

	void Draw();
};
