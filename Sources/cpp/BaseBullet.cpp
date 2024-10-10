#include "../Sources/header/BaseBullet.h"

void BaseBullet::Draw()
{
	// ���݂̍��W�ɋ��̂�`��
	DrawSphere3D(_position, _RADIUS, 32, _color, _BULLET_COLOR, TRUE);
}

void BaseBullet::Move()
{
	// �A�N�e�B�u�łȂ��Ȃ珈�����Ȃ�
	if (_active == false) return;

	// ���W�X�V
	_position = _nextBulletPosition;
}

void BaseBullet::CalNextPos()
{
	_nextBulletPosition.x = _position.x + cosf(_angle) * _speed;
	_nextBulletPosition.y = _position.y;
	_nextBulletPosition.z = _position.z - sinf(_angle) * _speed;

	collisionPosition.x = _position.x + cosf(_angle) * _speed;
	collisionPosition.y = _position.y;
	collisionPosition.z = _position.z - sinf(_angle) * _speed;
}

void BaseBullet::ChangePosition(VECTOR position)
{
	// ���݂̍��W��ύX����
	_position = position;
}

void BaseBullet::ChangeAngle(float angle)
{
	// ���݂̊p�x��ύX����
	_angle = angle;
}

void BaseBullet::ChangeActive(bool active)
{
	// ���݂̒e�ۂ̃A�N�e�B�u��؂�ւ���
	_active = active;
	// �e��p�����[�^�[�̏�����
	_hitWall = 0;
}

void BaseBullet::ChangeBounceNum(int num)
{
	_bounceNum = num;
}

void BaseBullet::HitWall()
{
	// �ǂɐڐG�����񐔂𑝂₷
	_hitWall++;
}

bool BaseBullet::JudgeBounce()
{
	if (_hitWall < _bounceNum) return true;
	else return false;
}