#pragma once
#include <DxLib.h>

class BaseObject
{
protected:

	struct Status
	{
		VECTOR m_position;		// 位置
		float m_life;			// オブジェクトの体力
		float m_shapeSize;		// 形の大きさ
		float m_angle;			// 向き
		bool m_canHit;			// 壁や弾などダメージが必要あるものかを区別
	};

	Status status;

	int objectModel;		// オブジェクトのモデル管理

	enum Shape				// 当たり判定の形区別するための情報
	{
		CIRCLE,
		SQUARE,
	};

	BaseObject();
	~BaseObject();

	void Draw();
};
