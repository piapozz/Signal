#include "../Sources/header/BaseBullet.h"

void BaseBullet::Draw()
{
	// 現在の座標に球体を描画
	DrawSphere3D(_position, _RADIUS, 32, _color, _BULLET_COLOR, TRUE);
}

void BaseBullet::Move()
{
	// アクティブでないなら処理しない
	if (_active == false) return;

	// 座標更新
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
	// 現在の座標を変更する
	_position = position;
}

void BaseBullet::ChangeAngle(float angle)
{
	// 現在の角度を変更する
	_angle = angle;
}

void BaseBullet::ChangeActive(bool active)
{
	// 現在の弾丸のアクティブを切り替える
	_active = active;
	// 各種パラメーターの初期化
	_hitWall = 0;
}

void BaseBullet::ChangeBounceNum(int num)
{
	_bounceNum = num;
}

void BaseBullet::HitWall()
{
	// 壁に接触した回数を増やす
	_hitWall++;
}

bool BaseBullet::JudgeBounce()
{
	if (_hitWall < _bounceNum) return true;
	else return false;
}