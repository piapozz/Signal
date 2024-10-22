#include "../header/Box.h"

Box::Box(Vector2 pos)
{
	// 座標指定
	SetPosition(pos);

	// 頂点の座標を求める
	CalVertexPos();
}

Box::Box(Vector2 pos, float life)
{
	// 座標指定
	SetPosition(pos);

	// 頂点の座標を求める
	CalVertexPos();

	// 体力設定
	status.m_life = life;
}

void Box::CalVertexPos()
{
	// 頂点までの長さ
	float length = sqrtf(powf(1 / 2, 2) * 2);

	// 四つ角分繰り返す
	for (int i = 0; i < 4; i++)
	{
		// 頂点までの角度
		float angle = status.m_angle + DX_PI / 4 + DX_PI / 2 * (i + 1);
		// 頂点までのベクトル
		Vector2 temp = Vector2(cosf(angle) * length, sinf(angle) * length);
		// 頂点の座標を保存
		vertex[i] = status.m_position + temp;
	}
}