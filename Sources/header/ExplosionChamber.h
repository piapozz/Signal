#pragma once

#include "BaseChamber.h"


class ExplosionChamber
	: public BaseChamber
{
public:

	ExplosionChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move() {};

	// �p�x�C���֐�
	void AngleModifying() {};

	// ���e�֐�
	void Impact() {};

	// ���Ŋ֐� 
	void Destroy() ;
};

