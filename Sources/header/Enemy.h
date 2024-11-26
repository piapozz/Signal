#pragma once
#include "BaseCharacter.h"
#include "CollisionManager.h"
#include "StageManager.h"

class Enemy : public BaseCharacter
{
private:

	BulletManager* _pBulletManager;
	std::vector<BaseCharacter*> _pPlayers;
	CollisionManager* _pCollisionManager;
	StageManager* _pStageManager;

	BaseObject* _targetObj;
	void SetTarget();
	void SelectPowerUp();

public:

	Enemy(Vector2 pos);
	~Enemy();

	void Init(BulletManager* bullet, std::vector<BaseCharacter*> players, CollisionManager* collisionManager, StageManager* stageManager);
	void Proc();
};
