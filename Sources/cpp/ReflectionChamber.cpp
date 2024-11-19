#include "../header/ReflectionChamber.h"


// ラジアンから方向ベクトルを取得
Vector2 RadianToVector2(float radian);

// 方向ベクトルからラジアンを取得
float Vector2ToRadian(Vector2 direction);

// 反射後のベクトルを計算
Vector2 ReflectVector(Vector2 direction, Vector2 normal);

// ラジアンの反射計算
float ReflectRadian(float radian, Vector2 normal);

// 反射カウントが残っていればfalse
bool ReflectionChamber::Impact()
{
	bool reflectionEnd = true;

	// 残っているならカウントを減らす
	bulletContainer->reflectionContainer.reflectionCount > 0 ?
		bulletContainer->reflectionContainer.reflectionCount-- : reflectionEnd = false;

    status->m_angle = ReflectRadian(status->m_angle , bulletContainer->reflectionContainer.norm);

	return reflectionEnd;
}

// ラジアンから方向ベクトルを取得
Vector2 RadianToVector2(float radian)
{
    return Vector2(cos(radian), sin(radian));
}

// 方向ベクトルからラジアンを取得
float Vector2ToRadian(Vector2 direction)
{
    return atan2(direction.y, direction.x) ;
}

// 反射後のベクトルを計算
Vector2 ReflectVector(Vector2 direction, Vector2 normal)
{
    normal.normalize(); // 法線は単位ベクトルである必要がある
    return (direction - 2.0f ) * ( normal * Vector2::Dot(direction, normal));
}

// ラジアンの反射計算
float ReflectRadian(float radian, Vector2 normal)
{
    Vector2 direction = RadianToVector2(radian); // ラジアンを方向ベクトルに変換
    Vector2 reflectedDirection = ReflectVector(direction, normal); // 反射後の方向ベクトル
    return Vector2ToRadian(reflectedDirection); // 反射後のラジアンを計算
}