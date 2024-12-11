#pragma once

#include "BaseChamber.h"

class ReflectionChamber
	: public BaseChamber
{
public:

	ReflectionChamber(BaseObject::Status* const& status,BulletContainer* const& container) : BaseChamber(status, container) {  }

	void Move() {}

	// �p�x�C���֐�
	void AngleModifying();

	// ���e�֐�
	bool Impact() const;

	// ���Ŋ֐� 
	void Destroy() {}
};

