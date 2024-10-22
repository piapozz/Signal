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

	Status GetStatus();			// �\���̂̏����擾

	Vector2 oldPosition;

protected:
	Status status;

	int objectHandle;		// �I�u�W�F�N�g�̌����ڂ��Ǘ��i���f����摜�j

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
