#pragma once
#include "DxLib.h"
#include "BaseObject.h"
#include "Box.h"
#include <vector>

class CollisionManager
{
private:

	
	
public:

	CollisionManager();
	~CollisionManager();

	bool HitCheckBaseObj(BaseObject obj1, BaseObject obj2);
	bool CheckBetweenObject(Vector2 pos1, Vector2 pos2, std::vector<Box*> boxList);
	bool CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2);
	void HitCheck_Player_Player(std::vector<BaseObject> players);
	void HitCheck_Player_Bullet(std::vector<BaseObject> players, std::vector<BaseObject> bullets);
	void HitCheck_Player_Box(std::vector<BaseObject> players, std::vector<Box> boxs);
	void HitCheck_Bullet_Box(std::vector<BaseObject> bullets, std::vector<Box> boxs);
};
