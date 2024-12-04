#include "../Sources/header/BaseChamber.h"

// コンストラクタ
BaseChamber::BaseChamber()
{

}


BaseChamber::BaseChamber(BaseObject::Status* const &objStatus,BulletContainer* const &container)
{
	status = objStatus;
	bulletContainer = container;
}

// デストラクタ
BaseChamber::~BaseChamber()
{

}
