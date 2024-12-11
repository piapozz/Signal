#include "../header/ReflectionChamber.h"

// ラジアンから方向ベクトルを取得
Vector2 RadianToVector2(float radian);

// 方向ベクトルからラジアンを取得
float Vector2ToRadian(Vector2 &direction);

// 反射後のベクトルを計算
Vector2 ReflectVector(Vector2& direction, Vector2& normal);

// ラジアンの反射計算
float ReflectRadian(float &radian, Vector2 &normal);

// 反射を角度に反映する
void ReflectionChamber::AngleModifying()
{

}

// 反射カウントが残っていればfalse
bool ReflectionChamber::Impact() const
{
    AudioManager::GetInstance().PlaySE(SEName::REFLECT);

    bool reflection = true;

    // 残っているならカウントを減らす
    bulletContainer->reflectionContainer->reflectionCount > 0 ?
        bulletContainer->reflectionContainer->reflectionCount-- : reflection = false;
    status->m_angle =
        ReflectRadian(status->m_angle, bulletContainer->reflectionContainer->norm);

    return reflection;
}

// ラジアンから方向ベクトルを取得
Vector2 RadianToVector2(float radian)
{
    return Vector2(cosf(radian), sinf(radian));
}

// 方向ベクトルからラジアンを取得
float Vector2ToRadian(Vector2 &direction)
{
    return (atan2f(direction.y, direction.x))* RAD;
}

// 反射後のベクトルを計算
Vector2 ReflectVector(Vector2 &direction,Vector2 &normal)
{
    normal.normalize(); // 法線は単位ベクトルである必要がある
    Vector2 result = (direction)-(normal * 2.0f * Vector2::Dot(direction, normal));
    return result;
}

// ラジアンの反射計算
float ReflectRadian(float &radian, Vector2 &normal)
{
    Vector2 direction = RadianToVector2(radian / RAD); // ラジアンを方向ベクトルに変換
    Vector2 reflectedDirection = ReflectVector(direction, normal); // 反射後の方向ベクトル
    return Vector2ToRadian(reflectedDirection); // 反射後のラジアンを計算
}