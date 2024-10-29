#pragma once

#include "BaseChamber.h"

class NormalChamber
	: public BaseChamber
{
public:

	NormalChamber(BaseObject::Status* status, MainContainer* container) : BaseChamber(status, container) {  }

	void Move();

	// Šp“xC³ŠÖ”
	void AngleModifying() {};

	// ’…’eŠÖ”
	void Impact() {};

	// Á–ÅŠÖ” 
	void Destroy() {};
};

