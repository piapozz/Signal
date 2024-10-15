#pragma once
#include "../header/BaseCharacter.h"

class Player : public BaseCharacter
{
private:
	int playerNum;


public:
	Player();
	~Player();

	void Proc();
	void SetPlayerNum(int playerNumber);
};