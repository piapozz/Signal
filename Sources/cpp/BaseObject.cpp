#include "../header/BaseObject.h"

BaseObject::BaseObject()
{

}

BaseObject::~BaseObject()
{

}

void BaseObject::Draw()
{
	// ���f����`��
	MV1DrawModel(objectModel);
}