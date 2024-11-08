#pragma once

#include "NormalChamber.h"
#include "ExplosionChamber.h"
#include "PenetrationChamber.h"
#include "TrackingChamber.h"
#include "ReflectionChamber.h"

// それぞれの関数を呼び出して移動などをする

class MainBullet
	: public BaseDamageObject
{
private:

	BaseChamber::BulletContainer _bulletContainer;

	float distance = 0;

	NormalChamber* normalChanber;

	float bulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
	int bulletType[(int)BulletType::MAX] = { 1,0,0,0,0,0 };

	void UpdateStatus();

public:

	MainBullet();
	~MainBullet();

	// 角度修正
	void UpdateAngle();

	// 移動
	void Move();

	// 着弾時
	void Impact();

	// 消滅時
	void Destroy();

	// 射程管理関数
	void CheckRange();

	// 座標、角度、ステータスセット
	void Reload(Status objStatus, float Pram[], int type[]);
};