#pragma once

#include "BaseChamber.h"


class ExplosionChamber
	: public BaseChamber
{
public:

	ExplosionChamber( BaseObject::Status* const &status, BulletContainer* const &container) : BaseChamber(status, container) {  }

	void Move() {}

	// Šp“xC³ŠÖ”
	void AngleModifying() {}

	// ’…’eŠÖ”
	inline bool Impact() const { return true; }

	// Á–ÅŠÖ” 
	void Destroy();
};

