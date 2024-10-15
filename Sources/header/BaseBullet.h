#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"
#include "BaseObject.h"
#include "Const.h"

class BaseBullet
	: public BaseObject
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

	ShotStatus _status;

	int graph = LoadGraph("char* FileName");

public:

	// コンストラクタ
	BaseBullet();
	BaseBullet(float bulletStatus[BulletStatus::MAX], Status objStatus);

	// デストラクタ
	~BaseBullet();

	// 描画関数
	void Draw();

	// 座標更新関数
	void virtual Move() = 0;
};