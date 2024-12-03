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
		int color = GetColor(0, 0, 0);	// 弾丸の色
	};

	// 反射ステータス
	struct ReflectionContainer
	{
		int reflectionCount = 0;		// 反射回数
		Vector2 norm;					// 法線
	public:
		void LevelUp(int level)
		{
			reflectionCount = level;
		}
	};

	// 貫通ステータス
	struct PenetrationContainer
	{
		int penetrationCount = 0;		// 貫通回数 
	public:
		void LevelUp(int level)
		{
			penetrationCount = level;
		}
	};

	// 爆発ステータス
	struct ExplosionContainer
	{
		float expansionRange = 1.0f;			// 一フレームごとに膨張する範囲
		float time = 0.5f;							// 持続時間
		bool active = false;					// 爆発の有効化
	public:
		void LevelUp(int level)
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
		int level[(int)BulletType::MAX];

	public:
		void LevelUp(int type[])
		{
			int temp[(int)BulletType::MAX];

			for (int i = 0; i < (int)BulletType::MAX; i++) 
			{
				temp[i] = type[i];
			}

			reflectionContainer->LevelUp(temp[(int)BulletType::REFLECTION]);
			penetrationContainer->LevelUp(temp[(int)BulletType::PENETRATION]);
			explosionContainer->LevelUp(temp[(int)BulletType::EXPLOSION]);
		}
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
	virtual bool Impact() = 0;

	// 消滅関数 
	virtual void Destroy() = 0;
	
};