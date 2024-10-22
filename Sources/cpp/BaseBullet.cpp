#include "../Sources/header/BaseBullet.h"

// �R���X�g���N�^
BaseBullet::BaseBullet() 
{

}

BaseBullet::BaseBullet(float bulletStatus[], Status objStatus)
{
	_status.m_Speed = bulletStatus[(int)BulletStatus::SPEED];
	_status.m_Power = bulletStatus[(int)BulletStatus::POWER];
	_status.m_Range = bulletStatus[(int)BulletStatus::RANGE];

	status = objStatus;
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
