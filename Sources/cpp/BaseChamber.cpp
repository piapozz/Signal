#include "../Sources/header/BaseChamber.h"

// �R���X�g���N�^
BaseChamber::BaseChamber()
{
	// �L����
	_status.m_Flag = true;
}

BaseChamber::BaseChamber(float bulletStatus[], Status objStatus)
{
	_status.m_Speed = bulletStatus[(int)BulletStatus::SPEED];
	_status.m_Power = bulletStatus[(int)BulletStatus::POWER];
	_status.m_Range = bulletStatus[(int)BulletStatus::RANGE];

	status = objStatus;

	// �L����
	_status.m_Flag = true;
}

// �f�X�g���N�^
BaseChamber::~BaseChamber()
{

}

// �`��֐�
void BaseChamber::Draw()
{
	// ��]�g�k�`��
	DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, DX_PI / 180 * status.m_angle, graph,TRUE);
}

// �˒��Ǘ��֐�
void BaseChamber::CheckRange()
{
	// �O�̍��W���狗�����o���đ����Ă���
	distance += Vector2::Distance(oldPosition, status.m_position);

	if (distance < _status.m_Range) return;

	Destroy();
}