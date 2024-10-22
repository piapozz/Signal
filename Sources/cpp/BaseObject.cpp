#include "../header/BaseObject.h"

BaseObject::BaseObject()
{

}

BaseObject::~BaseObject()
{

}

// 画像を描画
void BaseObject::Draw()
{
	// 画像を描画
	if (objectHandle != NULL) DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, status.m_angle * (DX_PI_F / 180), objectHandle, true);
	// ハンドルに何も入っていなかったら代わりに丸を生成
	else DrawCircle(status.m_position.x, status.m_position.y, 150, GetColor(255, 0, 0), FALSE);
}

// オブジェクトの座標変更
void BaseObject::SetPosition(Vector2 objectPos) { status.m_position = objectPos; }

// オブジェクトの体力を設定
void BaseObject::SetLife(float life) { status.m_life = life; }

// オブジェクトの向きを設定
void BaseObject::SetAngle(float angle) { status.m_angle = angle; }

// オブジェクトの大きさを設定
void BaseObject::SetShapeSize(float size) { status.m_shapeSize = size; }

// モデルデータをセット
void BaseObject::SetModelData(int model) { objectHandle = model; }


BaseObject::Status BaseObject::GetStatus() { return status; }