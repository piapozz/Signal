#pragma once
#include "BaseObject.h"
#include "BulletManager.h"
#include "InputManager.h"

class BaseCharacter : public BaseObject
{
private:
	float vecLength;					// ベクトルの長さ
	float selecting;					// 選択中のコマンドを代入

	float speed = 5;			// 自機のスピード
	float dodgeSpeed = 20;		// 回避の速さ
	float dodgeMoveCount;		// 回避の移動時間を管理
	float dodgeCooltime;		// 回避のクールタイムを管理
	float playerBombCount;

	int request;						// 次の要求量
	int lotteryPowerCount;				// パワーを抽選できる回数
	int lotteryStatusCount;				// ステータス抽選できる回数

	bool canLottery;					// 抽選を行うことができるかの管理
	bool choosePower;					// パワーの強化を実行してるかどうか
	bool chooseStatus;					// ステータスの強化を実行しているかどうか
	bool playerBomb;

public:
	const float DODGE_COOLTIME = 2000.0f;
	const float DODGE_MOVETIME = 250.0f;

	const float PLAYER_BOMB_TIME = 1000.0f;
	const int LEVEL_MAX = 10;

	int deviceNum;						// 弾の管理などに使う変数
	int playerNum;						// どのプレイヤーがどのコントローラーを使うのかを管理する
	int levelUpCount;

	std::vector<int> choicePower;		// パワーアップの選択肢を格納
	std::vector<int> choiceStatus;		// ステータスアップの選択肢を格納

	BaseCharacter(BulletManager* bullet);	// コンストラクタ
	~BaseCharacter();					// デストラクタ

	void Rotate(Vector2 stickAngle);
	void Move();
	void Dodge();
	void DodgeCoolTime();
	void LevelUp() {};
	void ObserveExp();
	void LotteryStatus();
	void LotteryPower();
	void ChooseBonus(int selectedButton);

	// 値の取得や変更を行う関数
	bool GetIsPlayer();
	bool GetIsInvincible();
	int GetExpValue();
	int GetRequestValue();
	void GainExp(int expValue);
	Vector2 GetPlayerPos();
	int GetChooceFlag();
	void SetSurvival();
	void SetPlayerNum(int playerNumber);

	virtual void Proc() = 0;

protected:
	BulletManager* bulletManager;

	Vector2 moveVec;

	int exp;					// 壊した箱の数を管理

	bool isInvincible;			// 無敵かどうか判断

	Vector2 dodgeVec;

	bool isPlayer;
	bool canDodge;
	bool dodgeNow;				// 回避している状態かを見る
};