#include "../Sources/header/BaseBullet.h"

// �R���X�g���N�^
BaseBullet::BaseBullet() 
{
	// �L����
	_status.m_Flag = true;
}

BaseBullet::BaseBullet(float bulletStatus[], Status objStatus)
{
	_status.m_Speed = bulletStatus[(int)BulletStatus::SPEED];
	_status.m_Power = bulletStatus[(int)BulletStatus::POWER];
	_status.m_Range = bulletStatus[(int)BulletStatus::RANGE];

	status = objStatus;

	// �L����
	_status.m_Flag = true;
}

// �f�X�g���N�^
BaseBullet::~BaseBullet()
{

}

// �`��֐�
void BaseBullet::Draw()
{
	// ��]�g�k�`��
	DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, DX_PI / 180 * status.m_angle, graph,TRUE);
}

// �˒��Ǘ��֐�
void BaseBullet::CheckRange() 
{

	Destroy();
}