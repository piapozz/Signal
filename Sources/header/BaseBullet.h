#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"
#include "BaseObject.h"

class BaseBullet
{
private:

	// 弾丸の色
	const int _BULLET_COLOR = GetColor(255, 0, 0);


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