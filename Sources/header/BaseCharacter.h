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
	int lotteryPowerCount;				// 抽選できる回数
	int lotteryStatusCount;				// 抽選できる回数

	std::vector<int> choicePower;		// パワーアップの選択肢を格納
	std::vector<int> choiceStatus;		// ステータスアップの選択肢を格納

	bool canLottery;					// 抽選を行うことができるかの管理
	bool canChoose;						// ボーナスを選ぶことができるかの管理

	BaseCharacter();					// コンストラクタ
	~BaseCharacter();					// デストラクタ

	void Rotate(Vector2 stickAngle);
	void Move();
	void Dodge();
	void LevelUp();
	void ObserveExp();
	void LotteryStatus();
	void LotteryPower();
	void ChooseBonus();

	// 値の取得や変更を行う関数
	bool GetIsPlayer();
	int GetExpValue();
	void GainExp(int expValue);
	void SetPlayerNum(int playerNumber);

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