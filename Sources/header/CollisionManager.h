#pragma once
#include <vector>
#include "DxLib.h"
#include "BaseObject.h"
#include "Box.h"
#include "StageManager.h"
#include "MainBullet.h"
#include "BulletManager.h"
#include "BaseCharacter.h"

class CollisionManager
{
private:

	
	
public:

	CollisionManager();
	~CollisionManager();

	bool HitCheck_BaseObj(BaseObject* obj1, BaseObject* obj2);
	bool HitCheck_BaseObj_Box(BaseObject* obj, Box* box);
	bool CheckBetweenObject(Vector2 pos1, Vector2 pos2, std::vector<Box*> boxList);
	bool CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2);
	void HitCheck_Player_Player(std::vector<BaseCharacter*> players);
	void HitCheck_Player_Bullet(std::vector<BaseCharacter*> players, BulletManager* bullet);
	void HitCheck_Player_Box(std::vector<BaseCharacter*> players, std::vector<Box*> boxs);
	void HitCheck_Bullet_Box(std::vector<Box*> boxs, BulletManager* bullet);
	void HitCheck_Everything(std::vector<BaseCharacter*> players, std::vector<Box*> boxs, BulletManager* bullet);
};
