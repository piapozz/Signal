#pragma once
#include <math.h>
#include <vector>
#include <string>
#include "DxLib.h"

// 二次元ベクトル
struct Vector2
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

    Vector2 operator*(Vector2 vec)
    {
        Vector2 temp;

        temp.x = x * vec.x;
        temp.y = y * vec.y;

        return temp;
    }

    Vector2 operator+(float num)
    {
        Vector2 temp;

        temp.x = x + num;
        temp.y = y + num;

        return temp;
    }

    Vector2 operator-(float num)
    {
        Vector2 temp;

        temp.x = x - num;
        temp.y = y - num;

        return temp;
    }

    Vector2 operator*(float num)
    {
        Vector2 temp;

        temp.x = x * num;
        temp.y = y * num;

        return temp;
    }

    Vector2 operator/(float num)
    {
        Vector2 temp;

        temp.x = x / num;
        temp.y = y / num;

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
        return Size(vec1 - vec2);
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

    static Vector2 Normalize(Vector2 vec)
    {
        Vector2 temp;
        float distance = vec.size();

        temp.x = vec.x / distance;
        temp.y = vec.y / distance;

        return temp;
    }

    static float Dot(Vector2 vec1, Vector2 vec2) 
    {
        return vec1.x * vec2.x + vec2.y * vec1.y;
    }

    static float Cross(Vector2 vec1, Vector2 vec2)
    {
        return vec1.x * vec2.y - vec2.x * vec1.y;
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

// 方位
enum class Cardinal
{
    WEST,
    NORTH,
    EAST,
    SOUTH,
    MAX
};

enum class ObjectType
{
    PLAYER = 0,
    BOX,
    WALL,
    BULLET,
    MAX
};

enum class BGMName
{
    IN_GAME = 0,

    MAX
};

enum class SEName
{
    SHOT = 0,
    IMPACT,
    LEVELUP,
    LEVELUP_DECIDE,
    EXPLOSION,
    DAMAGE,
    DODGE,
    REFLECT,
    BOMB,
    CURSOR_DECIDE,
    CURSOR_MOVE,
    GAMEEND,

    MAX
};

//const std::string BGM_ADRESS[(int)BGMName::MAX]
//{
//    "Resources/BGM.mp3",
//};

//const std::string SOUND_ADRESS[(int)SEName::MAX]
//{
//    "Resources/Audio/Shot.mp3",
//    "Resources/Audio/Impact.mp3",
//    "Resources/Audio/LevelUp.mp3",
//    "Resources/Audio/Levelup_Decide.mp3",
//    "Resources/Audio/Explosion.mp3",
//    "Resources/Audio/Damage.mp3",
//    "Resources/Audio/Dodge.mp3",
//    "Resources/Audio/Reflect.mp3",
//    "Resources/Audio/Bomb.mp3",
//    "Resources/Audio/Cursor_Decide.mp3",
//    "Resources/Audio/Cursor_Move.mp3",
//
//};

// プレイヤー
const int PLAYER_MAX = 2;		// プレイヤーの最大数

// 箱
const float BOX_SIZE = 100.0f;   // 箱のサイズ
const int REVIVAL_TIME = 1000;   // 復活までの時間
const float BOX_LIFE = 10.0f;

// 色データ
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);

// ステージ
const float STAGE_MARGIN_RATE = 0.1f;

// ウィンドウ
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// UI関連
const int CHOICE_POWER_MAX = 3;
const int CHOICE_STATUS_MAX = 3;
const float DISTANCE_ERROR = 20.0f;

const float BULLET_ICON_WIDTH = 75.0f;
const float BULLET_ICON_HEIGHT = 75.0f;

const int FONT_DEFAULT = 20;

const float RAD = (float)(180 / DX_PI);

extern Vector2 drawAnchorPos;				// ステージのアンカー座標
extern float drawRatio;