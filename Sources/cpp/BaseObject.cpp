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
	Vector2 drawPos = GetDisplayPos();

	float drawSize = status.m_shapeSize * drawRatio * drawUpScale;
	// �`��
	DrawRotaGraph(drawPos.x, drawPos.y, drawSize, status.m_angle / RAD, objectHandle, TRUE);
}

// ���ݍ��W�ɓK��
void BaseObject::UpdatePosition()
{
	// �ړ��\����W�ƃI�u�W�F�N�g�Ƃ̓����蔻������Ĉړ������������邩����i���̏�Ԃł͓����Ȃ��Ȃ�j
	if (hitObject != true)
	{
		// ���W���X�V
		status.m_position.x = status.m_nextPosition.x;
		status.m_position.y = status.m_nextPosition.y;
	}
	else { hitObject = false; }
}

// �t���O��؂�ւ���֐�
void BaseObject::SetHitFlag(bool hitCheck)
{
	hitObject = hitCheck;
}

// �_���[�W���󂯎��̗͂����炷�֐��֐�
bool BaseObject::TakeDamage(float damageSize)
{
	status.m_life -= damageSize;

	return status.m_life <= 0;
}

void BaseObject::SetActive(bool flag) { status.m_isActive = flag; }

bool BaseObject::GetActive() { return status.m_isActive; }

// �I�u�W�F�N�g�̍��W�ύX
void BaseObject::SetPosition(Vector2 objectPos) { status.m_position = objectPos; }

// �I�u�W�F�N�g�̗̑͂�ݒ�
void BaseObject::SetLife(float life) { status.m_life = life; }

// �I�u�W�F�N�g�̌�����ݒ�
void BaseObject::SetAngle(float angle) { status.m_angle = angle; }

// �I�u�W�F�N�g�̑傫����ݒ�
void BaseObject::SetShapeSize(float size) { status.m_shapeSize = size; }

// �C���[�W�f�[�^���Z�b�g
void BaseObject::SetImageData(const char* objName) { objectHandle = LoadGraph(objName); }

// �`���擾����
Shape BaseObject::GetShape() { return status.m_shape; }

BaseObject::Status BaseObject::GetStatus() { return status; }

// �@�����擾����֐�
Vector2 BaseObject::GetNormDir(Vector2 hitPos)
{
	return Vector2::Normalize(hitPos - status.m_position);
}

// �f�B�X�v���C���W���擾����֐�
Vector2 BaseObject::GetDisplayPos()
{
	return drawAnchorPos + status.m_position * drawRatio;
}
