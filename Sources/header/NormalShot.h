#pragma once

#include "BaseBullet.h"

class NormalShot
	: public BaseBullet
{
public:

	NormalShot(float bulletStatus[], Status objStatus) : BaseBullet(bulletStatus, objStatus) {  }

	void Move();

	// ’…’eŠÖ”
	void Impact();

	// ”j‰óŠÖ”
	void Destroy();
};

