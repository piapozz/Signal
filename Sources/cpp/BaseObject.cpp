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
	//if (objectHandle != NULL) DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, status.m_angle * (DX_PI_F / 180), objectHandle, true);
	// �n���h���ɉ��������Ă��Ȃ����������Ɋۂ𐶐�
	DrawCircle(status.m_position.x, status.m_position.y, status.m_shapeSize, GetColor(255, 0, 0), TRUE);
}

// �t���O��؂�ւ���֐�
void BaseObject::SetHitFlag(bool hitCheck)
{
	hitObject = hitCheck;
}

// �_���[�W���󂯎��̗͂����炷�֐��֐�
void BaseObject::TakeDamage(float damageSize)
{
	status.m_life -= damageSize;
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

// �`���擾����
Shape BaseObject::GetShape() { return status.m_shape; }

BaseObject::Status BaseObject::GetStatus() { return status; }