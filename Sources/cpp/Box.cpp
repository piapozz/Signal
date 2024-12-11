#include "../header/Box.h"

Box::Box(const Vector2& pos, const int& handle)
{
	// ���W�w��
	SetPosition(pos);
	status.m_nextPosition = pos;
	status.m_shapeSize = BOX_SIZE;

	// ���_�̍��W�����߂�
	CalVertexPos();

	_isWall = true;
	objectHandle = handle;
}

Box::Box(const Vector2& pos, const float& life, const float& revivalTime, const int& handle)
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
	objectHandle = handle;
	_revivalTime = revivalTime;
}

void Box::Init()
{

}

void Box::Draw()
{
	int x1 = drawAnchorPos.x + (int)_vertex[0].x * drawRatio;
	int y1 = drawAnchorPos.y + (int)_vertex[0].y * drawRatio;
	int x2 = drawAnchorPos.x + (int)_vertex[2].x * drawRatio;
	int y2 = drawAnchorPos.y + (int)_vertex[2].y * drawRatio;

	if (hitDamage)
	{
		// �_���[�W���󂯂Ă���sin�J�[�u��`���悤�ɕ`��䗦��ς���
		float ratio = (float)_hitCount / (float)BOX_HIT_COUNT;
		float sin = sinf(ratio * DX_PI_F);
		float hitScale = (BOX_HIT_SCALE * status.m_shapeSize * drawRatio);
		x1 -= hitScale * sin;
		y1 += hitScale * sin;
		x2 += hitScale * sin;
		y2 -= hitScale * sin;

		////���]����
		//SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);
		//DrawExtendGraph(x1, y1, x2, y2, objectHandle, TRUE);
		//���Z����
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155 + 100 * (1 - sin));
		DrawExtendGraph(x1, y1, x2, y2, objectHandle, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	else
	{
		DrawExtendGraph(x1, y1, x2, y2, objectHandle, TRUE);
	}
}

// ���_�̍��W���v�Z����֐�
void Box::CalVertexPos()
{
	// ���_�܂ł̒���
	float length = sqrtf(powf(status.m_shapeSize / 2, 2) * 2);

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
	_untilRevivalCount = _revivalTime;
}

void Box::RevivalCount()
{
	_untilRevivalCount--;
}

// �@����Ԃ��֐�
Vector2 Box::GetNormDir(const Vector2 hitPos)
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
Vector2 Box::GetVertexPos(const int& n)
{
	return _vertex[n];
}

// �������Ă���J�E���g�̏���������֐�
void Box::HitCount()
{
	if (hitDamage)
	{
		_hitCount++;
		if (_hitCount >= BOX_HIT_COUNT)
		{
			hitDamage = false;
			_hitCount = 0;
		}
	}
}
