#include <math.h>

const int PLAYER_MAX = 2;		// プレイヤーの最大数

enum BUTTON
{
	DOWN = 0,
	LEFT,
	RIGHT,
	UP,
	X,
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

enum STICK
{
	LEFT = 0,
	RIGHT,
	MAX
};

// 二次元ベクトル
typedef struct Vector2
{
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

    float Distance()
    {
        return 0;
    }

    float Size()
    {
        return sqrtf(powf(x, 2) + powf(y, 2));
    }

    void Normalize()
    {
        float distance = Size();
        
        x /= distance;
        y /= distance;
    }

};

// 弾のステータス
enum BulletStatus
{
    SPEED,
    POWER,
    RANGE,
    RATE,

    MAX
};

// 弾のタイプ
enum BulletType
{
    NORMAL,
    EXPLOSION,
    MULTI_SHOT,
    PENETRATION,
    REFLECTION,
    TRACKING_SHOT,

    MAX
};