#pragma once

#include "BaseDamageObject.h"

class Explosion:
	public BaseDamageObject
{
private:

	BaseChamber::ExplosionContainer ExplosionContainer;

public:

	// �����̖c��
	void Move(){}
};

