#pragma once

#include "BaseChamber.h"

class NormalChamber
	: public BaseChamber
{
public:

	NormalChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move();

	// �p�x�C���֐�
	void AngleModifying() {};

	// ���e�֐�
	void Impact() {};

	// ���Ŋ֐� 
	void Destroy() {};
};

