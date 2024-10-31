#pragma once
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
private:

public:

	Enemy(Vector2 pos);
	~Enemy();

	void Proc(BulletManager* bullet, InputManager* inputManager);
};
