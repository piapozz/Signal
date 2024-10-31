#pragma once
#include <math.h>
#include <vector>

const int PLAYER_MAX = 2;		// プレイヤーの最大数

const float BOX_SIZE = 100.0f;    // 箱のサイズ

const int STAGE_WIDTH = 5;
const int STAGE_HEIGHT = 5;

enum class DirButton
{
    DOWN = 0,
    LEFT,
    RIGHT,
    UP,
    MAX
};

enum class Button
{
	X = 0,
	Y,
	A,
	B,
	LEFT_BUTTON,
	RIGHT_BUTTON,
	LEFT_TRIGGER,
	RIGHT_TRIGGER,
	LEFT_STICK_BUTTON,
	RIGHT_STICK_BUTTON,

	MAX
};

enum class Stick
{
	LEFT = 0,
	RIGHT,
	MAX
};

enum class Shape				// 当たり判定の形区別するための情報
{
    CIRCLE = 0,
    SQUARE,
    MAX
};

// 二次元ベクトル
typedef struct Vector2
{
public:
    float x;
    float y;

    Vector2 operator+(Vector2 vec)
    {
        Vector2 temp;

        temp.x = x + vec.x;
        temp.y = y + vec.y;

        return temp;
    }

    Vector2 operator-(Vector2 vec)
    {
        Vector2 temp;

        temp.x = x - vec.x;
        temp.y = y - vec.y;

        return temp;
    }

    Vector2 operator*(float num)
    {
        Vector2 temp;

        temp.x = x * num;
        temp.y = y * num;

        return temp;
    }

    Vector2()
    {
        x = 0;
        y = 0;
    }

    Vector2(float X, float Y)
    {
        x = X;
        y = Y;
    }

    static float Distance(Vector2 vec1, Vector2 vec2)
    {
        return Size(vec1 - vec2);;
    }

    float size()
    {
        return sqrtf(powf(x, 2) + powf(y, 2));
    }

    static float Size(Vector2 vec)
    {
        return sqrtf(powf(vec.x, 2) + powf(vec.y, 2));
    }

    void normalize()
    {
        float distance = size();

        if (distance == 0) return;
        
        x /= distance;
        y /= distance;
    }

    Vector2 Normalize(Vector2 vec)
    {
        Vector2 temp;
        float distance = vec.size();

        temp.x = vec.x / distance;
        temp.y = vec.y / distance;

        return temp;
    }
};

// 弾のステータス
enum class BulletStatus
{
    SPEED,
    POWER,
    RANGE,
    RATE,

    MAX
};

// 弾のタイプ
enum class BulletType
{
    NORMAL,
    EXPLOSION,
    MULTI_SHOT,
    PENETRATION,
    REFLECTION,
    TRACKING_SHOT,

    MAX
};