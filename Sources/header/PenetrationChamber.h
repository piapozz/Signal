#pragma once

#include "BaseChamber.h"

class PenetrationChamber
	: public BaseChamber
{
public:

	PenetrationChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move(){}

	// Šp“xC³ŠÖ”
	void AngleModifying() {}

	// ’…’eŠÖ”
	bool Impact();

	// Á–ÅŠÖ” 
	void Destroy() {}
};

