#pragma once
#include "BaseObject.h"
#include "BulletManager.h"
#include "InputManager.h"

class BaseCharacter : public BaseObject
{
private:
	float vecLength;					// ベクトルの長さ
	float selecting;					// 選択中のコマンドを代入

public:
	int deviceNum;						// 弾の管理などに使う変数
	int playerNum;						// どのプレイヤーがどのコントローラーを使うのかを管理する
	int request;						// 次の要求量
	int levelUpCount;
	int powerUpCount;
	int statusUpCount;

	// int choicePower[CHOICE_POWER_MAX];
	// int choiceStatus[CHOICE_STATUS_MAX];

	std::vector<int> choicePower;
	std::vector<int> choiceStatus;

	bool choiceFlag;

	BaseCharacter();					// コンストラクタ
	~BaseCharacter();					// デストラクタ

	void SetPlayerNum(int playerNumber);
	void Rotate(Vector2 stickAngle);
	void Move();
	void Dodge();
	bool GetIsPlayer();
	void GainExp(int expValue);
	int GetExpValue();
	void LevelUp();
	void PowerUp();
	void StatusUp();

	virtual void Proc() = 0;

protected:
	Vector2 moveVec;

	int exp;					// 壊した箱の数を管理

	float speed = 100;			// 自機のスピード
	float dodgeSpeed;			// 回避の速さ
	float dodgeCount;			// 回避のクールタイム管理
	float dodgeFlame;			// 回避に使うフレーム数

	bool isPlayer;
	bool canDodge;
	bool dodgeNow;				// 回避している状態かを見る
};