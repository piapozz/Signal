#pragma once
#include <DxLib.h>
#include "../header/Const.h"

class BaseObject
{
protected:
	struct Status
	{
		Vector2 m_position;		// 位置
		float m_life;			// オブジェクトの体力
		float m_shapeSize;		// 形の大きさ
		float m_angle;			// 向き
	};

	Status status;

	enum Shape				// 当たり判定の形区別するための情報
	{
		CIRCLE,
		SQUARE,
	};

	int objectModel;		// オブジェクトのモデル管理

	bool canMove;			// 動けるかどうかを管理

	bool canHit;			// 壁や弾などダメージが必要あるものかを区別

	BaseObject();
	~BaseObject();

	void Draw();

	void SetPosition(VECTOR objectPos);
	void SetModelData(int model);
};
