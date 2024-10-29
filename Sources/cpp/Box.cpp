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

void Box::Draw()
{
	int x1 = _vertex[0].x;
	int y1 = _vertex[0].y;
	int x2 = _vertex[2].x;
	int y2 = _vertex[2].y;

	DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), TRUE);
}

// 頂点の座標を計算する関数
void Box::CalVertexPos()
{
	// 頂点までの長さ
	float length = sqrtf(powf(BOX_SIZE / 2, 2) * 2);

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

// 法線を返す関数
Vector2 Box::GetNormDir()
{

}

// 頂点座標を返す関数
Vector2 Box::GetVertexPos(int n)
{
	return _vertex[n];
}