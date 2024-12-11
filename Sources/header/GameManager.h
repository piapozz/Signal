#pragma once

#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "StageManager.h"
#include "BulletManager.h"
#include "UIManager.h"
#include "InputManager.h"
#include "Memory.h"
#include "AudioManager.h"

// ゲームの進行クラス

class GameManager
{
public:

	GameManager(InputManager* pInputManager) :_pInputManager(pInputManager), _pCollisionManager(new CollisionManager()),
		_pStageManager(new StageManager(_pCollisionManager)), _pUiManager(new UIManager()), _pBulletManager(new BulletManager(PLAYER_MAX)) {};				// コンストラクタ
	~GameManager();												// デストラクタ

	void Init();												// 初期化
	void Proc();												// 処理
	void Draw();												// 描画

	bool GetFinish();

	static int winDevice;

private:

	std::vector<BaseCharacter*> _pDevices;	// プレイヤーたちの可変長配列
	std::vector<Player*> _pPlayers;			// プレイヤーの配列
	std::vector<Enemy*> _pEnemys;			// 敵の配列
	CollisionManager* _pCollisionManager;	// 当たり判定
	StageManager* _pStageManager;			// ステージ
	BulletManager* _pBulletManager;			// 弾
	UIManager* _pUiManager;					// UI
	InputManager* _pInputManager;			// 入力

	bool _isFinish;

	void CheckFinish();
};

