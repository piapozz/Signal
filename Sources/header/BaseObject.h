#pragma once
#include <DxLib.h>
#include <math.h>
#include "../header/Const.h"
#include "../header/AudioManager.h"

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
		float m_power;
		bool m_isActive;		// ������
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
			m_power = 1.0f;
			m_isActive = true;
			m_shapeSize = 5.0f;
		}
	};

	Status GetStatus();			// �\���̂̏����擾

	BaseObject();							// �R���X�g���N�^
	~BaseObject();							// �f�X�g���N�^

	bool TakeDamage(float damageSize);
	void SetHitFlag(bool hitCheck);
	void Move() {};
	void UpdatePosition();

	void SetActive(bool flag);
	bool GetActive();
	void SetPosition(Vector2 objectPos);
	void SetLife(float life);
	void SetAngle(float angle);
	void SetShapeSize(float size);
	void SetImageData(const char* objName);
	void SetHitDamage(float hit);
	void Draw();
	virtual Vector2 GetNormDir(Vector2 hitPos);			// �@����Ԃ��֐�
	Shape GetShape();						// �`���擾
	Vector2 GetDisplayPos();
	bool GetIsHit() { return hitDamage; }

	Status status;

protected:

	int objectHandle;		// �I�u�W�F�N�g�̌����ڂ��Ǘ��i���f����摜�j

	bool canMove;			// �����邩�ǂ������Ǘ�
	bool hitObject;			// �I�u�W�F�N�g�Ƀq�b�g���������Ǘ�
	bool hitDamage = false;			// �_���[�W���󂯂���
	float drawUpScale = 0.01f;		// �`�掞�̏k��
};
