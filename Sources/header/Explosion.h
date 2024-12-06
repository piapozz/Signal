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

	// �����̖c��
	void Move();

	// �o�ߎ��Ԃ̃`�F�b�N
	void CheckExplosionTimeOver();
};

