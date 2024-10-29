#pragma once

#include "BaseChamber.h"

class NormalChamber
	: public BaseChamber
{
public:

	NormalChamber(float bulletStatus[], Status objStatus) : BaseChamber(bulletStatus, objStatus) {  }

	void Move() ;

	// ���e�֐�
	void Impact();

	// �j��֐�
	void Destroy();
};

