#pragma once
#include "DxLib.h"
#include "BaseObject.h"

class CollisionManager
{
private:


	
public:

	CollisionManager(){}
	~CollisionManager(){}

	bool HitCheck(BaseObject obj1, BaseObject obj2);
	bool CheckBetweenObject(Vector2 pos1, Vector2 pos2);
};
