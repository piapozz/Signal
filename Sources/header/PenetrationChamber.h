#pragma once

#include "BaseChamber.h"

class PenetrationChamber
	: public BaseChamber
{
public:

	PenetrationChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move(){}

	// �p�x�C���֐�
	void AngleModifying() {}

	// ���e�֐�
	bool Impact();

	// ���Ŋ֐� 
	void Destroy() {}
};

