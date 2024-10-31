#pragma once

#include "NormalChamber.h"
#include "ExplosionChamber.h"
#include "MultipleChamber.h"
#include "PenetrationChamber.h"
#include "TrackingChamber.h"
#include "ReflectionChamber.h"

// それぞれの関数を呼び出して移動などをする

class MainBullet
	: public BaseObject
{
private:

	BaseChamber::MainContainer _mainContainer;

	float distance = 0;

	NormalChamber* normalChanber;

	float bulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
	int bulletType[(int)BulletType::MAX] = { 1,0,0,0,0,0 };

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

	// 描画
	void Draw();

	// 射程管理関数
	void CheckRange();

	// 座標、角度、ステータスセット
	void Reload(Status objStatus, float Pram[], int type[]);

	// 使用中か返す
	bool GetActive() { return _mainContainer.m_Flag; }

	// パワーを返す
	int GetPower() 
	{ 
		Destroy();
		return _mainContainer.m_Power; 
	}
};