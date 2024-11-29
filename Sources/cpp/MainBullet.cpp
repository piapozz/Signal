#include "../header/MainBullet.h"

MainBullet::MainBullet()
{
	_bulletContainer = new BaseChamber::BulletContainer();

	// 与えられたタイプ、ステータスの情報をもとに最終的なステータスと画像を出す
	_chambers[(int)BulletType::NORMAL] = new NormalChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::EXPLOSION] = new ExplosionChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::PENETRATION] = new PenetrationChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::REFLECTION] = new ReflectionChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::TRACKING_SHOT] = new TrackingChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::MULTI_SHOT] = new NormalChamber(&status, _bulletContainer);

	objectHandle = LoadGraph("Resources/Enemy.png");

	status.m_isActive = false;
}

MainBullet::~MainBullet()
{
	// ポインタの削除
	for (int i = 0; i < (int)BulletType::MAX; i++) 
	{
		if(_chambers[i] != nullptr) delete _chambers[i];
	}
	delete _bulletContainer;
}

// 角度修正
void MainBullet::UpdateAngle()
{
	// 反射の角度反映
	_chambers[(int)BulletType::REFLECTION]->AngleModifying();

	// 誘導の角度修正
	_chambers[(int)BulletType::TRACKING_SHOT]->AngleModifying();
}

// 移動
void MainBullet::Move()
{
	// 通常の移動
	_chambers[(int)BulletType::NORMAL]->Move();
}

// 着弾時
void MainBullet::Impact(ObjectType hitType)
{
	if (hitBoxObject.size() > 0 && hitType != ObjectType::PLAYER) 
	{
		Box newObj =  *hitBoxObject[hitBoxObject.size() - 1];
		BaseChamber::ReflectionContainer temp;
		temp.norm = newObj.GetNormDir(status.m_position);
		_bulletContainer->reflectionContainer = &temp;
	}
	else if(hitType != ObjectType::PLAYER)
	{
		Box newObj = *hitBoxObject[0];
		BaseChamber::ReflectionContainer temp;
		temp.norm = newObj.GetNormDir(status.m_position);
		_bulletContainer->reflectionContainer = &temp;
	}

	switch (hitType)
	{
	case ObjectType::PLAYER:
		// 貫通の着弾
		if (_chambers[(int)BulletType::PENETRATION]->Impact()) return;
		break;
	case ObjectType::BOX:
		// 貫通の着弾
		if (_chambers[(int)BulletType::PENETRATION]->Impact()) return;
		// 反射の着弾
		if (_chambers[(int)BulletType::REFLECTION]->Impact()) return;
		break;
	case ObjectType::WALL:
		// 反射の着弾
		if (_chambers[(int)BulletType::REFLECTION]->Impact()) return;
		break;
	default:
		break;
	}

	Destroy();

}

// 消滅時
void MainBullet::Destroy()
{
	// 爆発の消滅時
	_chambers[(int)BulletType::EXPLOSION]->Destroy();

	// 使用を終わる
	status.m_isActive = false;
}

// 射程管理関数
void MainBullet::CheckRange()
{
	// 次の座標から距離を出して足していく
	_distance += Vector2::Distance(status.m_nextPosition, status.m_position);

	if (_distance < _bulletContainer->mainContainer->m_Range) return;

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
	UpdateStatus();
	hitBoxObject.clear();
	hitCharObject.clear();
	_bulletContainer->LevelUp(_bulletType);
}

// ステータスのレベルによって値を書き換える
void MainBullet::UpdateStatus()
{
	_bulletContainer->mainContainer->m_Speed = _bulletStatus[(int)BulletStatus::SPEED] * 2;
	_bulletContainer->mainContainer->m_Range = _bulletStatus[(int)BulletStatus::RANGE] * 500;
	damage = _bulletStatus[(int)BulletStatus::POWER] * 1;
}