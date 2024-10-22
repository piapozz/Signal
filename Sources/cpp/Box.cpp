#include "../header/Box.h"

Box::Box(Vector2 pos)
{
	// ���W�w��
	SetPosition(pos);

	// ���_�̍��W�����߂�
	CalVertexPos();
}

Box::Box(Vector2 pos, float life)
{
	// ���W�w��
	SetPosition(pos);

	// ���_�̍��W�����߂�
	CalVertexPos();

	// �̗͐ݒ�
	status.m_life = life;
}

void Box::CalVertexPos()
{
	// ���_�܂ł̒���
	float length = sqrtf(powf(1 / 2, 2) * 2);

	// �l�p���J��Ԃ�
	for (int i = 0; i < 4; i++)
	{
		// ���_�܂ł̊p�x
		float angle = status.m_angle + DX_PI / 4 + DX_PI / 2 * (i + 1);
		// ���_�܂ł̃x�N�g��
		Vector2 temp = Vector2(cosf(angle) * length, sinf(angle) * length);
		// ���_�̍��W��ۑ�
		vertex[i] = status.m_position + temp;
	}
}