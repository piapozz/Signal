#include "../Sources/header/BaseChamber.h"

// �R���X�g���N�^
BaseChamber::BaseChamber()
{

}


BaseChamber::BaseChamber(BaseObject::Status* objStatus, MainContainer* container)
{
	status = *objStatus;
	mainContainer = *container;
}

// �f�X�g���N�^
BaseChamber::~BaseChamber()
{

}
