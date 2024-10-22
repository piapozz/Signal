#pragma once
#include <math.h>

const int PLAYER_MAX = 2;		// �v���C���[�̍ő吔

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

enum class Shape				// �����蔻��̌`��ʂ��邽�߂̏��
{
    CIRCLE = 0,
    SQUARE,
    MAX
};

// �񎟌��x�N�g��
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

// �e�̃X�e�[�^�X
enum class BulletStatus
{
    SPEED,
    POWER,
    RANGE,
    RATE,

    MAX
};

// �e�̃^�C�v
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