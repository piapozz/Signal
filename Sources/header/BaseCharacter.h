#pragma once
#include "../header/BaseObject.h"
#include "BulletManager.h"
#include "InputManager.h"
#include <math.h>

class BaseCharacter : public BaseObject
{
public:
	int deviceNum;						// 弾の管理などに使う変数
	int playerNum;						// どのプレイヤーがどのコントローラーを使うのかを管理する

	BaseCharacter();					// コンストラクタ
	~BaseCharacter();					// デストラクタ

	void SetPlayerNum(int playerNumber);
	void Move(Vector2 moveVec);
	void UpdatePosition();
	void Rotate(Vector2 stickAngle);
	void Dodge();
	bool GetIsPlayer();
	void PowerUp();
	void StatusUp();

	virtual void Proc(BulletManager* bullet, InputManager* inputManager) = 0;

protected:

	int exp;					// 壊した箱の数を管理

	float speed = 1;				// 自機のスピード
	float dodgeSpeed;			// 回避の速さ
	float dodgeCount;			// 回避のクールタイム管理
	float dodgeFlame;			// 回避に使うフレーム数

	bool isPlayer;
	bool canDodge;
	bool dodgeNow;				// 回避している状態かを見る

};