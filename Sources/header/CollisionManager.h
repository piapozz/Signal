#pragma once
#include <vector>
#include "DxLib.h"
#include "BaseObject.h"
#include "Box.h"
#include "MainBullet.h"
#include "BulletManager.h"
#include "BaseCharacter.h"
#include "BaseDamageObject.h"

using namespace std;

class CollisionManager
{
private:

	vector<BaseCharacter*> _pPlayers;
	vector<Box*> _pBoxs;
	BulletManager* _pBullet;

	bool IsInProximity(BaseObject* obj1, BaseObject* obj2);
	bool HitCheck_BaseObj(BaseObject* obj1, BaseObject* obj2);
	bool HitCheck_BaseObj_Box(BaseObject* obj, Box* box);
	bool CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2);
	void HitCheck_Player_Player(BaseCharacter* player_1, BaseCharacter* player_2);
	void HitCheck_Player_Bullet(BaseCharacter* player, MainBullet* bullet);
	void HitCheck_Player_Box(BaseCharacter* player, Box* box);
	bool HitCheck_Bullet_Box(MainBullet* bullet, Box* box);
	
public:

	CollisionManager();
	~CollisionManager();

	void Init(vector<BaseCharacter*> players, vector<Box*> boxs, BulletManager* bullet);

	bool CheckHitRay(Vector2 pos1, Vector2 pos2);
	void HitCheck_Everything();
};
