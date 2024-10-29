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

// �@����Ԃ��֐�
Vector2 Box::GetNormDir()
{

}

// ���_���W��Ԃ��֐�
Vector2 Box::GetVertexPos(int n)
{
	return _vertex[n];
}