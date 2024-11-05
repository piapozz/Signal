#pragma once
#include <DxLib.h>
#include <math.h>
#include "../header/Const.h"

class BaseObject
{
public:
	struct Status
	{
		Vector2 m_position;		// 位置
		Vector2 m_nextPosition;	// 移動予定座標
		float m_angle;			// 向き
		float m_life;			// オブジェクトの体力
		float m_shapeSize;		// 形の大きさ
		float m_power;			// 相手に与えるダメージ
		bool m_isActive;		// 生存状況
		Shape m_shape;			// 形

		// ステータスの初期化
		Status()
		{
			m_position.x = 0.0f;
			m_position.y = 0.0f;
			m_nextPosition.x = 0.0f;
			m_nextPosition.y = 0.0f;
			m_angle = 0.0;
			m_life = 1.0f;
			m_power = 0.0f;
			m_isActive = true;
			m_shapeSize = 5.0f;
		}
	};

	Status GetStatus();			// 構造体の情報を取得

	BaseObject();							// コンストラクタ
	~BaseObject();							// デストラクタ

	void TakeDamage(float damageSize);
	void SetHitFlag(bool hitCheck);
	virtual void Move() = 0;
	void UpdatePosition();

	void SetPosition(Vector2 objectPos);
	void SetLife(float life);
	void SetAngle(float angle);
	void SetShapeSize(float size);
	void SetImageData(const char* objName);
	void Draw();

	Shape GetShape();						// 形を取得

	Status status;
protected:

	int objectHandle;		// オブジェクトの見た目を管理（モデルや画像）

	bool canMove;			// 動けるかどうかを管理
	bool hitObject;			// オブジェクトにヒットしたかを管理
};
