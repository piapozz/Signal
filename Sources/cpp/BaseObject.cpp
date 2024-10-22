#include "../header/BaseObject.h"

BaseObject::BaseObject()
{

}

BaseObject::~BaseObject()
{

}

// �摜��`��
void BaseObject::Draw()
{
	// �摜��`��
	if (objectHandle != NULL) DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, status.m_angle * (DX_PI_F / 180), objectHandle, true);
	// �n���h���ɉ��������Ă��Ȃ����������Ɋۂ𐶐�
	else DrawCircle(status.m_position.x, status.m_position.y, 150, GetColor(255, 0, 0), FALSE);
}

// �I�u�W�F�N�g�̍��W�ύX
void BaseObject::SetPosition(Vector2 objectPos) { status.m_position = objectPos; }

// �I�u�W�F�N�g�̗̑͂�ݒ�
void BaseObject::SetLife(float life) { status.m_life = life; }

// �I�u�W�F�N�g�̌�����ݒ�
void BaseObject::SetAngle(float angle) { status.m_angle = angle; }

// �I�u�W�F�N�g�̑傫����ݒ�
void BaseObject::SetShapeSize(float size) { status.m_shapeSize = size; }

// ���f���f�[�^���Z�b�g
void BaseObject::SetModelData(int model) { objectHandle = model; }


BaseObject::Status BaseObject::GetStatus() { return status; }