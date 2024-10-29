#include "../header/NormalChamber..h"


void NormalChamber::Move()
{
	oldPosition = status.m_position;

	status.m_position.x = status.m_position.x + cosf(status.m_angle) * _status.m_Speed;
	status.m_position.y = status.m_position.y - sinf(status.m_angle) * _status.m_Speed;
}

// ’…’eŠÖ”
void NormalChamber::Impact()
{
	Destroy();
}

// ”j‰óŠÖ”
void  NormalChamber::Destroy()
{
	_status.m_Flag = false;
}