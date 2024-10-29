#include "../Sources/header/BaseChamber.h"

// コンストラクタ
BaseChamber::BaseChamber()
{
	// 有効化
	_status.m_Flag = true;
}

BaseChamber::BaseChamber(float bulletStatus[], Status objStatus)
{
	_status.m_Speed = bulletStatus[(int)BulletStatus::SPEED];
	_status.m_Power = bulletStatus[(int)BulletStatus::POWER];
	_status.m_Range = bulletStatus[(int)BulletStatus::RANGE];

	status = objStatus;

	// 有効化
	_status.m_Flag = true;
}

// デストラクタ
BaseChamber::~BaseChamber()
{

}

// 描画関数
void BaseChamber::Draw()
{
	// 回転拡縮描画
	DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, DX_PI / 180 * status.m_angle, graph,TRUE);
}

// 射程管理関数
void BaseChamber::CheckRange()
{
	// 前の座標から距離を出して足していく
	distance += Vector2::Distance(oldPosition, status.m_position);

	if (distance < _status.m_Range) return;

	Destroy();
}