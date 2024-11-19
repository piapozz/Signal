#pragma once

#include "BaseChamber.h"

class TrackingChamber
	: public BaseChamber
{
public:

	TrackingChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move() {}

	// Šp“xC³ŠÖ”
	void AngleModifying();

	// ’…’eŠÖ”
	bool Impact() { return true; }

	// Á–ÅŠÖ” 
	void Destroy() {}
};

