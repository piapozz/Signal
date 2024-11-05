#pragma once
#include <vector>
#include "DxLib.h"
#include "BaseObject.h"
#include "Box.h"
#include "StageManager.h"
#include "MainBullet.h"
#include "BulletManager.h"
#include "BaseCharacter.h"
#include "BaseDamageObject.h"

class CollisionManager
{
private:

	bool IsInProximity(BaseObject* obj1, BaseObject* obj2);
	bool HitCheck_BaseObj(BaseObject* obj1, BaseObject* obj2);
	bool HitCheck_BaseObj_Box(BaseObject* obj, Box* box);
	bool CheckBetweenObject(Vector2 pos1, Vector2 pos2, std::vector<Box*> boxList);
	bool CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2);
	void HitCheck_Player_Player(BaseCharacter* player_1, BaseCharacter* player_2);
	void HitCheck_Player_Bullet(BaseCharacter* player, MainBullet* bullet);
	void HitCheck_Player_Box(BaseCharacter* player, Box* box);
	bool HitCheck_Bullet_Box(MainBullet* bullet, Box* box);
	
public:

	CollisionManager();
	~CollisionManager();

	void HitCheck_Everything(std::vector<BaseCharacter*> players, std::vector<Box*> boxs, BulletManager* bullet);
};
