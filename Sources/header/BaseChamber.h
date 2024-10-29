#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"
#include "BaseObject.h"
#include "Const.h"

// ① バレットステータス構造体を改造純粋仮想関数の用意
// ステータス、画像の改造関数
// 角度修正関数
// 移動関数
// 着弾関数
// 消滅関数
// ② レベルに応じた効果の上昇関数を作成
// 貫通数
// 爆発範囲
// 反射回数
// 誘導係数
// ③ それらに伴う補助関数

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

protected:

	BaseBullet b;

	ShotStatus _status;

	int graph = LoadGraph("char* FileName");

	float distance = 0;

public:

	// コンストラクタ
	BaseBullet();
	BaseBullet(float bulletStatus[], Status objStatus);

	// デストラクタ
	~BaseBullet();

	// 描画関数
	void Draw();

	// 射程管理関数
	void CheckRange();

	// 座標更新関数
	void Move() {};

	// 着弾関数
	void Impact() {};

	// 破壊関数
	void Destroy() {};

	// 有効かどうか返す
	bool CheckActive() { return _status.m_Flag; }
};