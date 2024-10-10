#include "../header/BaseObject.h"

BaseObject::BaseObject()
{

}

BaseObject::~BaseObject()
{

}

// ���f����`��
void BaseObject::Draw()
{
	// ���f����`��
	if (objectModel != NULL) MV1DrawModel(objectModel);
	else DrawCircle(status.m_position.x, status.m_position.z, 150, GetColor(255, 0, 0), FALSE);

}

// �I�u�W�F�N�g�̍��W�ύX
void BaseObject::SetPosition(VECTOR objectPos)
{
	status.m_position = objectPos;
}

// ���f���f�[�^���Z�b�g
void BaseObject::SetModelData(int model)
{
	objectModel = model;
}