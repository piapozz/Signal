#include "../Sources/header/BaseChamber.h"

// �R���X�g���N�^
BaseChamber::BaseChamber()
{

}


BaseChamber::BaseChamber(BaseObject::Status* const &objStatus,BulletContainer* const &container)
{
	status = objStatus;
	bulletContainer = container;
}

// �f�X�g���N�^
BaseChamber::~BaseChamber()
{

}
