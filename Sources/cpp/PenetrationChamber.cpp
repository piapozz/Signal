#include "../header/PenetrationChamber.h"

// �ђʃJ�E���g���c���Ă����false
bool PenetrationChamber::Impact() 
{
	bool penetrationEnd = false;

	// �c���Ă���Ȃ�J�E���g�����炷
	bulletContainer->penetrationContainer.penetrationCount > 0 ?
		bulletContainer->penetrationContainer.penetrationCount-- : penetrationEnd = true;

	return penetrationEnd;
}