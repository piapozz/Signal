#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"

class BaseBullet
{
private:


	// �����蔻��̎��
	enum
	{
		SPHERE = 0,
		LINE,
		PLANE,
	};

	// �����̎��
	enum
	{
		FRONT = 0,
		BACK,
		LEFT,
		RIGHT,
		DIR_MAX
	};

	// �����蔻��̌`��
	int collisionShape;

	// ����I�u�W�F�N�g�̒��S���W
	VECTOR collisionPosition;

	// �I�u�W�F�N�g�̓����蔻��̔��a
	float collisionRadius;

	// �|���S���̒��_���W
	// �ǂ̎l�ʁ~1�̖ʂ̒��_
	VECTOR vertexPosition[DIR_MAX][4];

	// �ڐG�����ʂ̕���
	int hitSide;

	// �ڐG�����ǂ̔ԍ�
	int hitWallNum;

	// �ڐG���Ă���ǂ̐�
	int hitWallCount;

	// ��̍���
	const float BASE_HIGHT = 150.0f;

	// ���W
	VECTOR _position = VGet(0.0f, 0.0f, 0.0f);
	// �ړ���̍��W
	VECTOR _nextBulletPosition = VGet(0.0f, 0.0f, 0.0f);
	// ���ˊp�x
	float _angle = 0.0f;
	// �ˌ�����Ă��邩�ǂ���
	bool _active;
	// �e�ۂ̐F
	int _color;
	// �e��
	float _speed;
	//�ǂɔ��˂ł���ő吔
	int _bounceNum = 1;
	// �ǂɐڐG������
	int _hitWall = 0;
	// �ǈȊO�ɐڐG�������̃t���O
	bool _hitOther = false;
	// �e�ۂ̔��a
	const float _RADIUS = 20.0f;
	// �e�ۂ̓����蔻��̌`��
	const int _COLLISION_SHAPE = SPHERE;
	// �e�ۂ̐F
	const int _BULLET_COLOR = GetColor(255, 0, 0);


public:

	// �C�j�V�����C�U
	BaseBullet(bool shootable, bool active, int color, float speed) :
		_active(active), _color(color), _speed(speed)
	{
		// �����蔻��̐ݒ�
		collisionRadius = _RADIUS;			// ���a
		collisionShape = _COLLISION_SHAPE;	// �`��
		collisionPosition = _position;		// ���W
	};

	// �f�X�g���N�^
	~BaseBullet() {};

	// �`��֐�
	void Draw();

	// ���W�X�V�֐�
	void Move();

	// ���̍��W���v�Z����֐�
	void CalNextPos();

	// ���W��ύX����֐�
	void ChangePosition(VECTOR position);

	// �p�x��ύX����֐�
	void ChangeAngle(float angle);

	// �A�N�e�B�u��؂�ւ���֐�
	void ChangeActive(bool active);

	// ���ˉ񐔂�ύX����֐�
	void ChangeBounceNum(int num);

	// �ǂƐڐG���Ă��邩��ύX����֐�
	void HitWall();

	// ���˂���Ă��邩���擾����֐�
	bool GetActive() const { return _active; }

	// ���W���擾����֐�
	VECTOR GetPosition() const { return _position; }

	// ���W���擾����֐�
	float GetRadius() const { return _RADIUS; }

	// �����x�N�g�����擾����֐�
	VECTOR GetDirVec() { return VSub(_nextBulletPosition, _position); }

	// �ǂɓ����������ɔ��˂��邩���肷��֐�
	bool JudgeBounce();
};