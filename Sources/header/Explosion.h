#pragma once

#include "BaseDamageObject.h"
#include "BaseChamber.h"

class Explosion:
	public BaseDamageObject
{
private:

	BaseChamber::ExplosionContainer _explosionContainer;
	float _time;

public:

	Explosion();
	Explosion(BaseChamber::ExplosionContainer container , Status objStatus);
	~Explosion();

	// 爆発の膨張
	void Move();

	// 経過時間のチェック
	void CheckExplosionTimeOver();
};

