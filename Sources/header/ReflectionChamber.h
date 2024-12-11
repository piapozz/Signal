#pragma once

#include "BaseChamber.h"

class ReflectionChamber
	: public BaseChamber
{
public:

	ReflectionChamber(BaseObject::Status* const& status,BulletContainer* const& container) : BaseChamber(status, container) {  }

	void Move() {}

	// Šp“xC³ŠÖ”
	void AngleModifying();

	// ’…’eŠÖ”
	bool Impact() const;

	// Á–ÅŠÖ” 
	void Destroy() {}
};

