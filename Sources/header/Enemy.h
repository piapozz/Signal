#pragma once
#include "BaseCharacter.h"
#include "CollisionManager.h"

class Enemy : public BaseCharacter
{
private:

	BulletManager* _pBulletManager;
	std::vector<BaseCharacter*> _pPlayers;
	CollisionManager* _pCollisionManager;

	bool _isObstacle;

public:

	Enemy(Vector2 pos);
	~Enemy();

	void Init(BulletManager* bullet, InputManager* inputManager, std::vector<BaseCharacter*> players);
	void Init(CollisionManager* collisionManager);
	void Proc();
};
