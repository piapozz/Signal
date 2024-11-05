#include "../Sources/header/BaseChamber.h"

// コンストラクタ
BaseChamber::BaseChamber()
{

}


BaseChamber::BaseChamber(BaseObject::Status* objStatus, BulletContainer* container)
{
	status = objStatus;
	bulletContainer = container;
}

// デストラクタ
BaseChamber::~BaseChamber()
{

}
