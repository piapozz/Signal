#include "../Sources/header/BaseBullet.h"

// コンストラクタ
BaseBullet::BaseBullet() 
{

}

BaseBullet::BaseBullet(float bulletStatus[BulletStatus::MAX], Status objStatus)
{
	_status.m_Speed = bulletStatus[BulletStatus::SPEED];
	_status.m_Power = bulletStatus[BulletStatus::POWER];
	_status.m_Range = bulletStatus[BulletStatus::RANGE];

	status = objStatus;
}

// デストラクタ
BaseBullet::~BaseBullet()
{

}

// 描画関数
void BaseBullet::Draw()
{
	// 回転拡縮描画
	DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, DX_PI / 180 * status.m_angle, graph,TRUE);
}
