#pragma once

#include "BaseChamber.h"

class TrackingChamber
	: public BaseChamber
{
public:

	TrackingChamber(BaseObject::Status* const &status, BulletContainer* const &container) : BaseChamber(status, container) {  }

	void Move() {}

	// �p�x�C���֐�
	void AngleModifying() {};

	// ���e�֐�
	inline bool Impact() const { return true; }

	// ���Ŋ֐� 
	void Destroy() {}
};

