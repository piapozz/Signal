#pragma once
#include <DxLib.h>
#include <math.h>
#include "../header/Const.h"
#include "../header/AudioManager.h"

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
		float m_power;
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
			m_power = 1.0f;
			m_isActive = true;
			m_shapeSize = 5.0f;
		}
	};

	Status GetStatus();			// 構造体の情報を取得

	BaseObject();							// コンストラクタ
	~BaseObject();							// デストラクタ

	bool TakeDamage(float damageSize);
	void SetHitFlag(bool hitCheck);
	void Move() {};
	void UpdatePosition();

	void SetActive(bool flag);
	bool GetActive();
	void SetPosition(Vector2 objectPos);
	void SetLife(float life);
	void SetAngle(float angle);
	void SetShapeSize(float size);
	void SetImageData(const char* objName);
	void SetHitDamage(float hit);
	void Draw();
	virtual Vector2 GetNormDir(Vector2 hitPos);			// 法線を返す関数
	Shape GetShape();						// 形を取得
	Vector2 GetDisplayPos();
	bool GetIsHit() { return hitDamage; }

	Status status;

protected:

	int objectHandle;		// オブジェクトの見た目を管理（モデルや画像）

	bool canMove;			// 動けるかどうかを管理
	bool hitObject;			// オブジェクトにヒットしたかを管理
	bool hitDamage = false;			// ダメージを受けたか
	float drawUpScale = 0.01f;		// 描画時の縮尺
};
