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

	bool IsInProximity(BaseObject* obj1, BaseObject* obj2) const;
	bool CheckLineCross(const Vector2& a, const Vector2& b, const Vector2& c, const Vector2& d) const;
	bool HitCheck_BaseObj_Box(BaseObject* obj, Box* box) const;
	bool HitCheck_BaseObj(BaseObject* obj1, BaseObject* obj2) const;
	void HitCheck_Player_Player(BaseCharacter* player_1, BaseCharacter* player_2);
	void HitCheck_Player_Bullet(BaseCharacter* player, MainBullet* bullet);
	void HitCheck_Player_Explosion(BaseCharacter* player, Explosion* explosion);
	void HitCheck_Player_Box(BaseCharacter* player, Box* box);
	bool HitCheck_Bullet_Box(MainBullet* bullet, Box* box);
	bool HitCheck_Explosion_Box(Explosion* explosion, Box* box);
	
public:

	CollisionManager();
	~CollisionManager();

	void Init(const vector<BaseCharacter*>& players, const vector<Box*>& boxs, BulletManager* bullet);

	bool CheckHitRay(const Vector2& pos1, const Vector2& pos2) const;
	void HitCheck_Everything();
	void UpdateHitObj();
	bool HitCheckBox_Other(Box* box);
};
