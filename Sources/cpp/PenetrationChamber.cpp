#include "../header/PenetrationChamber.h"

// 貫通カウントが残っていればfalse
bool PenetrationChamber::Impact() 
{
	bool penetration = true;

	// 残っているならカウントを減らす
	bulletContainer->penetrationContainer->penetrationCount > 0 ?
		bulletContainer->penetrationContainer->penetrationCount -- : penetration = false;

	return penetration;
}