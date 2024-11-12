#pragma once

#include "BaseDamageObject.h"

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

class BaseChamber
{
public:

	// 基礎ステータス
	typedef struct MainContainer
	{
		float m_Speed = 5.0f;   // スピード
		float m_Range = 300.0f;	// 射程
		int color = GetColor(0, 0, 0);	// 弾丸の色
	};

	// 反射ステータス
	typedef struct ReflectionContainer
	{

	};

	// 誘導ステータス
	typedef struct TrackingContainer
	{
		float turnAngle = 5;			// 補正する角度
		Vector2 targetPosition;			// 誘導対象
	};

	// 貫通ステータス
	typedef struct PenetrationContainer
	{

	};

	// 爆発ステータス
	typedef struct ExplosionContainer
	{
		float expansionRange;			// 膨張する範囲

	};

	// 弾の構造体
	typedef struct BulletContainer
	{
		MainContainer mainContainer;
		ReflectionContainer reflectionContainer;
		TrackingContainer trackingContainer;
		PenetrationContainer penetrationContainer;
		ExplosionContainer explosionContainer;
	};

protected:
		
	BaseObject::Status* status;
	BulletContainer* bulletContainer;

public:


	// コンストラクタ
	BaseChamber();
	BaseChamber(BaseObject::Status *status, BulletContainer*container);

	// デストラクタ
	~BaseChamber();

	// 角度修正関数
	virtual void AngleModifying() = 0;
	
	// 移動関数
	virtual void Move() = 0;

	// 着弾関数
	virtual void Impact() = 0;

	// 消滅関数 
	virtual void Destroy() = 0;
	
};