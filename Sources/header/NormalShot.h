#pragma once

#include "BaseBullet.h"

class NormalShot
	: public BaseBullet
{
public:

	NormalShot(float bulletStatus[], Status objStatus) : BaseBullet(bulletStatus, objStatus) {  }

	void Move();

	// ���e�֐�
	void Impact();

	// �j��֐�
	void Destroy();
};

