#pragma once

#include "BaseDamageObject.h"
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

class BaseChamber
{
public:

	// 基礎ステータス
	 struct MainContainer
	{
		float m_Speed = 5.0f;			// スピード
		float m_Range = 1.0f;			// 射程
	};

	// 反射ステータス
	struct ReflectionContainer
	{
		int reflectionCount = 0;		// 反射回数
		Vector2 norm;					// 法線
	public:
		void LevelUp(const int &level)
		{
			reflectionCount = level;
		}
	};

	// 貫通ステータス
	struct PenetrationContainer
	{
		int penetrationCount = 0;		// 貫通回数 
	public:
		void LevelUp(const int &level)
		{
			penetrationCount = level * 2;
		}
	};

	// 爆発ステータス
	struct ExplosionContainer
	{
		float expansionRange = 1.0f;			// 一フレームごとに膨張する範囲
		float time = 0.5f;							// 持続時間
		bool active = false;					// 爆発の有効化
	public:
		void LevelUp(const int &level)
		{
			expansionRange = level * 1.0f;
		}

	};

	// 弾の構造体
	struct BulletContainer
	{
		MainContainer* mainContainer = new MainContainer();
		ReflectionContainer* reflectionContainer = new ReflectionContainer();
		PenetrationContainer* penetrationContainer = new PenetrationContainer();
		ExplosionContainer* explosionContainer = new ExplosionContainer();

	public:
		void LevelUp(int type[])
		{
			reflectionContainer->LevelUp(type[(int)BulletType::REFLECTION]);
			penetrationContainer->LevelUp(type[(int)BulletType::PENETRATION]);
			explosionContainer->LevelUp(type[(int)BulletType::EXPLOSION]);
		}
	};

protected:
		
	BaseObject::Status* status;
	BulletContainer* bulletContainer;

public:

	// コンストラクタ
	BaseChamber();
	BaseChamber(BaseObject::Status* const &status,BulletContainer* const &container);

	// デストラクタ
	~BaseChamber();

	// 角度修正関数
	virtual void AngleModifying() = 0;
	
	// 移動関数
	virtual void Move() = 0;

	// 着弾関数
	virtual bool Impact() = 0;

	// 消滅関数 
	virtual void Destroy() = 0;
	
};