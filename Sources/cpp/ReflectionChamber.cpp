#include "../header/ReflectionChamber.h"


// ���W�A����������x�N�g�����擾
Vector2 RadianToVector2(float radian);

// �����x�N�g�����烉�W�A�����擾
float Vector2ToRadian(Vector2 direction);

// ���ˌ�̃x�N�g�����v�Z
Vector2 ReflectVector(Vector2 direction, Vector2 normal);

// ���W�A���̔��ˌv�Z
float ReflectRadian(float radian, Vector2 normal);

// ���˃J�E���g���c���Ă����false
bool ReflectionChamber::Impact()
{
	bool reflectionEnd = true;

	// �c���Ă���Ȃ�J�E���g�����炷
	bulletContainer->reflectionContainer->reflectionCount > 0 ?
		bulletContainer->reflectionContainer->reflectionCount-- : reflectionEnd = true;

    status->m_angle = ReflectRadian(status->m_angle , bulletContainer->reflectionContainer->norm);

	return reflectionEnd;
}

// ���W�A����������x�N�g�����擾
Vector2 RadianToVector2(float radian)
{
    return Vector2(sinf(radian), cosf(radian));
}

// �����x�N�g�����烉�W�A�����擾
float Vector2ToRadian(Vector2 direction)
{
    return (atan2f(direction.y, direction.x))* RAD;
}

// ���ˌ�̃x�N�g�����v�Z
Vector2 ReflectVector(Vector2 direction, Vector2 normal)
{
    normal.normalize(); // �@���͒P�ʃx�N�g���ł���K�v������
    return (direction) - ( normal * ( 2.0f * Vector2::Dot(direction, normal)));
}

// ���W�A���̔��ˌv�Z
float ReflectRadian(float radian, Vector2 normal)
{
    Vector2 direction = RadianToVector2(radian); // ���W�A��������x�N�g���ɕϊ�
    Vector2 reflectedDirection = ReflectVector(direction, normal); // ���ˌ�̕����x�N�g��
    return Vector2ToRadian(reflectedDirection); // ���ˌ�̃��W�A�����v�Z
}