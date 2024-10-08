#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"

class BaseBullet
{
private:


	// 当たり判定の種類
	enum
	{
		SPHERE = 0,
		LINE,
		PLANE,
	};

	// 方向の種類
	enum
	{
		FRONT = 0,
		BACK,
		LEFT,
		RIGHT,
		DIR_MAX
	};

	// 当たり判定の形状
	int collisionShape;

	// 球状オブジェクトの中心座標
	VECTOR collisionPosition;

	// オブジェクトの当たり判定の半径
	float collisionRadius;

	// ポリゴンの頂点座標
	// 壁の四面×1つの面の頂点
	VECTOR vertexPosition[DIR_MAX][4];

	// 接触した面の方向
	int hitSide;

	// 接触した壁の番号
	int hitWallNum;

	// 接触している壁の数
	int hitWallCount;

	// 基準の高さ
	const float BASE_HIGHT = 150.0f;

	// 座標
	VECTOR _position = VGet(0.0f, 0.0f, 0.0f);
	// 移動後の座標
	VECTOR _nextBulletPosition = VGet(0.0f, 0.0f, 0.0f);
	// 発射角度
	float _angle = 0.0f;
	// 射撃されているかどうか
	bool _active;
	// 弾丸の色
	int _color;
	// 弾速
	float _speed;
	//壁に反射できる最大数
	int _bounceNum = 1;
	// 壁に接触した回数
	int _hitWall = 0;
	// 壁以外に接触したかのフラグ
	bool _hitOther = false;
	// 弾丸の半径
	const float _RADIUS = 20.0f;
	// 弾丸の当たり判定の形状
	const int _COLLISION_SHAPE = SPHERE;
	// 弾丸の色
	const int _BULLET_COLOR = GetColor(255, 0, 0);


public:

	// イニシャライザ
	BaseBullet(bool shootable, bool active, int color, float speed) :
		_active(active), _color(color), _speed(speed)
	{
		// 当たり判定の設定
		collisionRadius = _RADIUS;			// 半径
		collisionShape = _COLLISION_SHAPE;	// 形状
		collisionPosition = _position;		// 座標
	};

	// デストラクタ
	~BaseBullet() {};

	// 描画関数
	void Draw();

	// 座標更新関数
	void Move();

	// 次の座標を計算する関数
	void CalNextPos();

	// 座標を変更する関数
	void ChangePosition(VECTOR position);

	// 角度を変更する関数
	void ChangeAngle(float angle);

	// アクティブを切り替える関数
	void ChangeActive(bool active);

	// 反射回数を変更する関数
	void ChangeBounceNum(int num);

	// 壁と接触しているかを変更する関数
	void HitWall();

	// 発射されているかを取得する関数
	bool GetActive() const { return _active; }

	// 座標を取得する関数
	VECTOR GetPosition() const { return _position; }

	// 座標を取得する関数
	float GetRadius() const { return _RADIUS; }

	// 方向ベクトルを取得する関数
	VECTOR GetDirVec() { return VSub(_nextBulletPosition, _position); }

	// 壁に当たった時に反射するか判定する関数
	bool JudgeBounce();
};