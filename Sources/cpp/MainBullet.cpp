#include "../header/MainBullet.h"

MainBullet::MainBullet()
{
	// 与えられたタイプ、ステータスの情報をもとに最終的なステータスと画像を出す
	_normalChanber = new NormalChamber(&status, &_bulletContainer);

	status.m_isActive = false;
}

MainBullet::~MainBullet()
{

}

// 角度修正
void MainBullet::UpdateAngle()
{
	// 反射の角度補正

	// 誘導の角度修正

}

// 移動
void MainBullet::Move()
{
	// 通常の移動
	_normalChanber->Move();
}

// 着弾時
void MainBullet::Impact()
{
	// 貫通の着弾

	// 反射の着弾

	Destroy();

}

// 消滅時
void MainBullet::Destroy()
{
	// 爆発の消滅時


	// 使用を終わる
	status.m_isActive = false;
}

// 射程管理関数
void MainBullet::CheckRange()
{
	// 次の座標から距離を出して足していく
	_distance += Vector2::Distance(status.m_nextPosition, status.m_position);

	if (_distance < _bulletContainer.mainContainer.m_Range) return;

	Destroy();
}

// 座標、角度、ステータスセット
void MainBullet::Reload(Status objStatus, float Pram[], int type[])
{
	status = objStatus;

	for (int i = 0; i < (int)BulletStatus::MAX; i++) 
	{
		_bulletStatus[i] = Pram[i];
	}

	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		_bulletType[i] = type[i];
	}

	// 使用中
	status.m_isActive = true;
	_distance = 0;
}

// ステータスのレベルによって値を書き換える
void MainBullet::UpdateStatus()
{
	_bulletContainer.mainContainer.m_Speed = _bulletType[(int)BulletStatus::SPEED] * 5;
	_bulletContainer.mainContainer.m_Range = _bulletType[(int)BulletStatus::RANGE] * 300;
	damage = _bulletType[(int)BulletStatus::POWER] * 1;
}