#pragma once

#include "BaseChamber.h"


class ExplosionChamber
	: public BaseChamber
{
public:

	ExplosionChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move() {};

	// Šp“xC³ŠÖ”
	void AngleModifying() {};

	// ’…’eŠÖ”
	void Impact() {};

	// Á–ÅŠÖ” 
	void Destroy() ;
};

