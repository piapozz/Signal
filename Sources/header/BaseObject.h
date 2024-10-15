#pragma once
#include <DxLib.h>
#include "../header/Const.h"

class BaseObject
{
public:
	struct Status
	{
		Vector2 m_position;		// �ʒu
		float m_life;			// �I�u�W�F�N�g�̗̑�
		float m_angle;			// ����
		float m_shapeSize;		// �`�̑傫��
	};

protected:
	Status status;

	enum Shape				// �����蔻��̌`��ʂ��邽�߂̏��
	{
		CIRCLE,
		SQUARE,
	};

	int objectModel;		// �I�u�W�F�N�g�̃��f���Ǘ�

	bool canMove;			// �����邩�ǂ������Ǘ�
	bool canHit;			// �ǂ�e�Ȃǃ_���[�W���K�v������̂������
	bool hitObject;			// �I�u�W�F�N�g�Ƀq�b�g���������Ǘ�
	bool hitBullet;			// �e�Ƀq�b�g���������Ǘ�

	BaseObject();
	~BaseObject();

	void Draw();

	void SetPosition(Vector2 objectPos);
	void SetModelData(int model);
};
