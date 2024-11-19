#pragma once

#include "BaseChamber.h"

class NormalChamber
	: public BaseChamber
{
public:

	NormalChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move();

	// Šp“xC³ŠÖ”
	void AngleModifying() {}

	// ’…’eŠÖ”
	bool Impact() { return true; }

	// Á–ÅŠÖ” 
	void Destroy() {}
};

