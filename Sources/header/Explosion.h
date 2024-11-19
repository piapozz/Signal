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

	// �����̖c��
	void Move();

	// �o�ߎ��Ԃ̃`�F�b�N
	void CheckExplosionTimeOver();
};

