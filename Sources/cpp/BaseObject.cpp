#include "../header/BaseObject.h"

BaseObject::BaseObject()
{

}

BaseObject::~BaseObject()
{

}

// モデルを描画
void BaseObject::Draw()
{
	// モデルを描画
	if (objectModel != NULL) MV1DrawModel(objectModel);
	else DrawCircle(status.m_position.x, status.m_position.z, 150, GetColor(255, 0, 0), FALSE);

}

// オブジェクトの座標変更
void BaseObject::SetPosition(VECTOR objectPos)
{
	status.m_position = objectPos;
}

// モデルデータをセット
void BaseObject::SetModelData(int model)
{
	objectModel = model;
}