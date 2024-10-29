#include "../Sources/header/BaseChamber.h"

// コンストラクタ
BaseChamber::BaseChamber()
{

}


BaseChamber::BaseChamber(BaseObject::Status* objStatus, MainContainer* container)
{
	status = *objStatus;
	mainContainer = *container;
}

// デストラクタ
BaseChamber::~BaseChamber()
{

}
