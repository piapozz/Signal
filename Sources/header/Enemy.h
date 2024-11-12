#pragma once
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
private:

	BulletManager* _pBulletManager;
	std::vector<BaseCharacter*> _pPlayers;
	CollisionManager* _pCollisionManager;

public:

	Enemy(Vector2 pos);
	~Enemy();

	void Init(BulletManager* bullet, InputManager* inputManager, std::vector<BaseCharacter*> players, CollisionManager* collisionManager);
	void Proc();
};
