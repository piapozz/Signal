#include "../header/NormalShot.h"


void NormalShot::Move() 
{
	status.m_position.x = status.m_position.x + cosf(status.m_angle) * _status.m_Speed;
	status.m_position.y = status.m_position.y - sinf(status.m_angle) * _status.m_Speed;
}

// ’…’eŠÖ”
void NormalShot::Impact()
{
	Destroy();
}

// ”j‰óŠÖ”
void  NormalShot::Destroy()
{
	_status.m_Flag = false;
}