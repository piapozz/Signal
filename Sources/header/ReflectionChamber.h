#pragma once

#include "BaseChamber.h"

class ReflectionChamber
	: public BaseChamber
{
private:

	bool frameFlag = false;

public:

	ReflectionChamber(BaseObject::Status* status, BulletContainer* container) : BaseChamber(status, container) {  }

	void Move() {}

	// �p�x�C���֐�
	void AngleModifying();

	// ���e�֐�
	bool Impact();

	// ���Ŋ֐� 
	void Destroy() {}
};

