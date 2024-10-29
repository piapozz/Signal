#pragma once

#include "NormalShot.h"
#include "ExplosionShot.h"
#include "MultipleShot.h"
#include "PenetrationShot.h"
#include "TrackingShot.h"
#include "ReflectionShot.h"

// BaseBulletポインタをコンストラクタを渡す
// それぞれの関数を呼び出して移動などをする

class MixBullet
{
private:

	// 弾丸の色
	const int _BULLET_COLOR = GetColor(0, 0, 0);

	typedef struct ShotStatus
	{
		bool m_Flag = false;    // 発射フラグ
		float m_Speed = 5.0f;   // スピード
		float m_Power = 1.0f;	// 破壊力	
		float m_Range = 3.0f;	// 射程
	};

protected:

	ShotStatus _status;

	int graph = LoadGraph("char* FileName");

	float distance = 0;

public:

	MixBullet();
	~MixBullet();

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
};