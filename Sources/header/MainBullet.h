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

	MainBullet(const int &handle);
	~MainBullet();

	// 角度修正
	void UpdateAngle();

	// 移動
	void Move();

	// 着弾時
	void Impact(const ObjectType &hitType);

	// 消滅時
	void Destroy();

	// 射程管理関数
	void CheckRange();

	// 座標、角度、ステータスセット
	void Reload(const Status &objStatus,const float Pram[],const int type[]);

	// 弾の性質を取得
	inline int GetBulletType(const BulletType &type) const { return _bulletType[(int)type]; }

	// 爆発が有効かどうか
	inline bool GetExplosion() const
	{
		if (_bulletContainer->explosionContainer->active)
		{
			_bulletContainer->explosionContainer->active = false;
			return true;
		}
		return  false;
	}

	inline BaseChamber::ExplosionContainer GetExplosionStatus() const { return *_bulletContainer->explosionContainer; }
};