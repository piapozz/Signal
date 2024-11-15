#pragma once

#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "StageManager.h"
#include "BulletManager.h"
#include "UIManager.h"
#include "InputManager.h"

// ゲームの進行クラス

class GameManager
{							
public:

	GameManager();												// コンストラクタ
	~GameManager();												// デストラクタ

	void Init();												// 初期化
	void Proc();												// 処理
	void Draw();												// 描画

private:

	std::vector<BaseCharacter*> devices;	// プレイヤーたちの可変長配列
	std::vector<Player*> players;			// プレイヤーの配列
	std::vector<Enemy*> enemys;				// 敵の配列
	CollisionManager* collisionManager;	// 当たり判定
	StageManager* stageManager;			// ステージ
	BulletManager* bulletManager;		// 弾
	UIManager* uiManager;				// UI
	InputManager* inputManager;			// 入力

	int playerMax;

};

