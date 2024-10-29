#include "../header/GameManager.h"

// コンストラクタ
GameManager::GameManager()
{
	player = new Player();
	enemy = new Enemy();
	collisionManager = new CollisionManager();
	stageManager = new StageManager();
	//bulletManager = new BulletManager();
	uiManager = new UIManager();
	inputManager = new InputManager();
}

// デストラクタ
GameManager::~GameManager() 
{
	delete player;				// プレイヤー
	delete enemy;				// エネミー
	delete collisionManager;	// 当たり判定
	delete stageManager;		// ステージ
	delete bulletManager;		// 弾
	delete uiManager;			// UI
	delete inputManager;		// 入力
}

// 初期化
void GameManager::Init() 
{
	// プレイヤーの数を取得
	playerMax = inputManager->GetPlayerNum();

	// 弾を人数分用意
	bulletManager = new BulletManager(playerMax);

}


// 処理
void GameManager::Proc()
{
	// 入力取得
	inputManager->Proc();

	// プレイヤーの移動

	// 敵の移動

	// 弾の移動
	bulletManager->Move();

	// 当たり判定
	collisionManager->
}

// 描画
void GameManager::Draw()
{
	bulletManager->Draw();
}


