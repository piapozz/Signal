#pragma once

#include "BaseDamageObject.h"
#include "NormalChamber.h"
#include "ExplosionChamber.h"
#include "PenetrationChamber.h"
#include "TrackingChamber.h"
#include "ReflectionChamber.h"
#include "Box.h"

// それぞれの関数を呼び出して移動などをする

class MainBullet
	: public BaseDamageObject
{
private:

	BaseChamber::BulletContainer* _bulletContainer = new BaseChamber::BulletContainer();

	float _distance = 0;

	BaseChamber* _chambers[(int)BulletType::MAX];

	float _bulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
	int _bulletType[(int)BulletType::MAX] = { 1,0,0,0,0 };

	void UpdateStatus();

public:

	MainBullet(int handle);
	~MainBullet();

	// 角度修正
	void UpdateAngle();

	// 移動
	void Move();

	// 着弾時
	void Impact(ObjectType hitType);

	// 消滅時
	void Destroy();

	// 射程管理関数
	void CheckRange();

	// 座標、角度、ステータスセット
	void Reload(Status objStatus, float Pram[], int type[]);

	// 弾の性質を取得
	int GetBulletType(BulletType type) { return _bulletType[(int)type]; }

	// 爆発が有効かどうか
	bool GetExplosion() 
	{
		if (_bulletContainer->explosionContainer->active)
		{
			_bulletContainer->explosionContainer->active = false;
			return true;
		}
		return  false;
	}

	BaseChamber::ExplosionContainer GetExplosionStatus() { return *_bulletContainer->explosionContainer; }
};