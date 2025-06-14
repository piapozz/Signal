#include "../header/Box.h"

Box::Box(const Vector2& pos, const int& handle)
{
	// 座標指定
	SetPosition(pos);
	status.m_nextPosition = pos;
	status.m_shapeSize = BOX_SIZE;

	// 頂点の座標を求める
	CalVertexPos();

	_isWall = true;
	objectHandle = handle;
}

Box::Box(const Vector2& pos, const float& life, const float& revivalTime, const int& handle)
{
	// 座標指定
	SetPosition(pos);
	status.m_nextPosition = pos;
	status.m_shapeSize = BOX_SIZE;

	// 頂点の座標を求める
	CalVertexPos();

	// 体力設定
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
		// ダメージを受けてからsinカーブを描くように描画比率を変える
		float ratio = (float)_hitCount / (float)BOX_HIT_COUNT;
		float sin = sinf(ratio * DX_PI_F);
		float hitScale = (BOX_HIT_SCALE * status.m_shapeSize * drawRatio);
		x1 -= hitScale * sin;
		y1 += hitScale * sin;
		x2 += hitScale * sin;
		y2 -= hitScale * sin;

		////反転合成
		//SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);
		//DrawExtendGraph(x1, y1, x2, y2, objectHandle, TRUE);
		//加算合成
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155 + 100 * (1 - sin));
		DrawExtendGraph(x1, y1, x2, y2, objectHandle, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	else
	{
		DrawExtendGraph(x1, y1, x2, y2, objectHandle, TRUE);
	}
}

// 頂点の座標を計算する関数
void Box::CalVertexPos()
{
	// 頂点までの長さ
	float length = sqrtf(powf(status.m_shapeSize / 2, 2) * 2);

	// 四つ角分繰り返す
	for (int i = 0; i < 4; i++)
	{
		// 頂点までの角度
		float angle = status.m_angle + DX_PI / 4 + DX_PI / 2 * (i + 1);
		// 頂点までのベクトル
		Vector2 temp = Vector2(cosf(angle) * length, sinf(angle) * length);
		// 頂点の座標を保存
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

// 法線を返す関数
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

// 頂点座標を返す関数
Vector2 Box::GetVertexPos(const int& n)
{
	return _vertex[n];
}

// 当たってたらカウントの処理をする関数
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
