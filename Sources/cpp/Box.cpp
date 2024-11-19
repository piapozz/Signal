#include "../header/Box.h"

Box::Box(Vector2 pos)
{
	// ���W�w��
	SetPosition(pos);
	status.m_nextPosition = pos;
	status.m_shapeSize = BOX_SIZE;

	// ���_�̍��W�����߂�
	CalVertexPos();

	_isWall = true;
}

Box::Box(Vector2 pos, float life)
{
	// ���W�w��
	SetPosition(pos);
	status.m_nextPosition = pos;
	status.m_shapeSize = BOX_SIZE;

	// ���_�̍��W�����߂�
	CalVertexPos();

	// �̗͐ݒ�
	status.m_life = life;
	_maxLife = life;

	_exp = 1;

	_isWall = false;
}

void Box::Draw()
{
	int x1 = _vertex[0].x;
	int y1 = _vertex[0].y;
	int x2 = _vertex[2].x;
	int y2 = _vertex[2].y;

	DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), TRUE);
}

// ���_�̍��W���v�Z����֐�
void Box::CalVertexPos()
{
	// ���_�܂ł̒���
	float length = sqrtf(powf(BOX_SIZE / 2, 2) * 2);

	// �l�p���J��Ԃ�
	for (int i = 0; i < 4; i++)
	{
		// ���_�܂ł̊p�x
		float angle = status.m_angle + DX_PI / 4 + DX_PI / 2 * (i + 1);
		// ���_�܂ł̃x�N�g��
		Vector2 temp = Vector2(cosf(angle) * length, sinf(angle) * length);
		// ���_�̍��W��ۑ�
		_vertex[i] = status.m_position + temp;
	}
}

void Box::RevivalBox()
{
	SetActive(true);
	status.m_life = _maxLife;
}

void Box::DestroyBox()
{
	SetActive(false);
	_untilRevivalCount = REVIVAL_TIME;
}

void Box::RevivalCount()
{
	_untilRevivalCount--;
}

// �@����Ԃ��֐�
Vector2 Box::GetNormDir(Vector2 hitPos)
{
	Vector2 dir = hitPos - GetStatus().m_position;
	float angle = atan2f(dir.y, dir.x);

	Vector2 result;
	if (angle >= -DX_PI_F / 4 * 3 && angle < -DX_PI_F / 4 * 1)
		result = Vector2(0, -1);
	else if (angle >= -DX_PI_F / 4 * 1 && angle < DX_PI_F / 4 * 1)
		result = Vector2(1, 0);
	else if (angle >= DX_PI_F / 4 * 1 && angle < DX_PI_F / 4 * 3)
		result = Vector2(0, 1);
	else
		result = Vector2(-1, 0);

	return result;
}

// ���_���W��Ԃ��֐�
Vector2 Box::GetVertexPos(int n)
{
	return _vertex[n];
}