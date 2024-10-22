#pragma once
#include <DxLib.h>
#include "../header/Const.h"

class BaseObject
{
public:
	struct Status
	{
		Vector2 m_position;		// 位置
		float m_life;			// オブジェクトの体力
		float m_angle;			// 向き
		float m_shapeSize;		// 形の大きさ
	};

	Status GetStatus();			// 構造体の情報を取得

	Vector2 oldPosition;

protected:
	Status status;

	int objectHandle;		// オブジェクトの見た目を管理（モデルや画像）

	bool canMove;			// 動けるかどうかを管理
	bool canHit;			// 壁や弾などダメージが必要あるものかを区別
	bool hitObject;			// オブジェクトにヒットしたかを管理
	bool hitBullet;			// 弾にヒットしたかを管理

	BaseObject();
	~BaseObject();

	void Draw();

	void SetPosition(Vector2 objectPos);
	void SetModelData(int model);
};
