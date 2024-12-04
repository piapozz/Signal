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
	Vector2 drawPos = GetDisplayPos();

	float drawSize = status.m_shapeSize * drawRatio * drawUpScale;
	// 描画
	DrawRotaGraph(drawPos.x, drawPos.y, drawSize, status.m_angle / RAD, objectHandle, TRUE);
}

// 現在座標に適応
void BaseObject::UpdatePosition()
{
	// 移動予定座標とオブジェクトとの当たり判定を見て移動を完了させるか分岐（この状態では動けなくなる）
	if (hitObject != true)
	{
		// 座標を更新
		status.m_position.x = status.m_nextPosition.x;
		status.m_position.y = status.m_nextPosition.y;
	}
	else { hitObject = false; }
}

// フラグを切り替える関数
void BaseObject::SetHitFlag(bool hitCheck)
{
	hitObject = hitCheck;
}

// ダメージを受け取り体力を減らす関数関数
bool BaseObject::TakeDamage(float damageSize)
{
	status.m_life -= damageSize;

	return status.m_life <= 0;
}

void BaseObject::SetActive(bool flag) { status.m_isActive = flag; }

bool BaseObject::GetActive() { return status.m_isActive; }

// オブジェクトの座標変更
void BaseObject::SetPosition(Vector2 objectPos) { status.m_position = objectPos; }

// オブジェクトの体力を設定
void BaseObject::SetLife(float life) { status.m_life = life; }

// オブジェクトの向きを設定
void BaseObject::SetAngle(float angle) { status.m_angle = angle; }

// オブジェクトの大きさを設定
void BaseObject::SetShapeSize(float size) { status.m_shapeSize = size; }

// イメージデータをセット
void BaseObject::SetImageData(const char* objName) { objectHandle = LoadGraph(objName); }

// 形を取得する
Shape BaseObject::GetShape() { return status.m_shape; }

BaseObject::Status BaseObject::GetStatus() { return status; }

// 法線を取得する関数
Vector2 BaseObject::GetNormDir(Vector2 hitPos)
{
	return Vector2::Normalize(hitPos - status.m_position);
}

// ディスプレイ座標を取得する関数
Vector2 BaseObject::GetDisplayPos()
{
	return drawAnchorPos + status.m_position * drawRatio;
}
