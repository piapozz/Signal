#pragma once

#include "BaseChamber.h"

class TrackingChamber
	: public BaseChamber
{
public:

	TrackingChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move() {}

	// �p�x�C���֐�
	void AngleModifying();

	// ���e�֐�
	bool Impact() { return true; }

	// ���Ŋ֐� 
	void Destroy() {}
};

