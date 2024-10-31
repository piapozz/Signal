#include "../header/NormalChamber.h"


void NormalChamber::Move()
{
	status->m_nextPosition.x = status->m_position.x + cosf(status->m_angle) * mainContainer->m_Speed;
	status->m_nextPosition.y = status->m_position.y + sinf(status->m_angle) * mainContainer->m_Speed;
}