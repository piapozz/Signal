#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"
#include "BaseObject.h"

class BaseBullet
	: public BaseObject
{
private:

	// 弾丸の色
	const int _BULLET_COLOR = GetColor(0, 0, 0);

	typedef struct ShotStatus
	{
		bool MslFlg = false;    // 発射フラグ
		const float MslSpeed = 5.0f;    // スピード
	};

public:

	// イニシャライザ
	BaseBullet(){ };

	// デストラクタ
	~BaseBullet() {};

	// 描画関数
	void Draw();

	// 座標更新関数
	void Move();
};