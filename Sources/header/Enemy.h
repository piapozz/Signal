#pragma once
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
private:

	CollisionManager* colManager;

public:

	Enemy();
	~Enemy();

	void Proc();
};
