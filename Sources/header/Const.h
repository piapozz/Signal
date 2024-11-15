#pragma once
#include <math.h>
#include <vector>

// �v���C���[
const int PLAYER_MAX = 2;		// �v���C���[�̍ő吔

// ��
const float BOX_SIZE = 100.0f;  // ���̃T�C�Y
const int REVIVAL_TIME = 300;   // �����܂ł̎���
const float BOX_LIFE = 10.0f;

// �X�e�[�W
const float STAGE_MARGIN_RATE = 0.1f;

// �E�B���h�E
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// UI�֘A
const int CHOICE_POWER_MAX = 3;
const int CHOICE_STATUS_MAX = 3;

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

enum class ObjectType
{
    PLAYER = 0,
    BOX,
    WALL,
    BULLET,
    MAX
};

// �񎟌��x�N�g��
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

    static float Cross(Vector2 vec1, Vector2 vec2)
    {
        return vec1.x * vec2.y - vec2.x * vec1.y;
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