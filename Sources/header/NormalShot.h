#pragma once

#include "BaseBullet.h"

class NormalShot
	: public BaseBullet
{
public:

	NormalShot(float bulletStatus[BulletStatus::MAX], Status objStatus) : BaseBullet(bulletStatus, objStatus) {  }

	void  Move() override;

	// ’…’eŠÖ”
	void Impact() override;

	// ”j‰óŠÖ”
	void Destroy() override;
};

