#pragma once

#include "BaseDamageObject.h"
#include "BaseChamber.h"

class Explosion:
	public BaseDamageObject
{
private:

	BaseChamber::ExplosionContainer _explosionContainer;
	int _time;

public:

	Explosion();
	Explosion(const BaseChamber::ExplosionContainer &container, const Status &objStatus);
	~Explosion();

	// 爆発の膨張
	void Move();

	// 経過時間のチェック
	void CheckExplosionTimeOver();
};

