#include "../header/PenetrationChamber.h"

// �ђʃJ�E���g���c���Ă����false
bool PenetrationChamber::Impact() 
{
	bool penetration = true;

	// �c���Ă���Ȃ�J�E���g�����炷
	bulletContainer->penetrationContainer->penetrationCount > 0 ?
		bulletContainer->penetrationContainer->penetrationCount -- : penetration = false;

	return penetration;
}