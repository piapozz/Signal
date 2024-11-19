#include "../header/PenetrationChamber.h"

// 貫通カウントが残っていればfalse
bool PenetrationChamber::Impact() 
{
	bool penetrationEnd = false;

	// 残っているならカウントを減らす
	bulletContainer->penetrationContainer.penetrationCount > 0 ?
		bulletContainer->penetrationContainer.penetrationCount-- : penetrationEnd = true;

	return penetrationEnd;
}