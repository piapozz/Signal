#include "../header/GameManager.h"

// コンストラクタ
GameManager::GameManager()
{
	players.push_back(new Player());
	players.push_back(new Enemy());
	collisionManager = new CollisionManager();
	stageManager = new StageManager();
	//bulletManager = new BulletManager();
	uiManager = new UIManager();
	inputManager = new InputManager();
}

// デストラクタ
GameManager::~GameManager() 
{
	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}
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
	playerMax = players.size();

	// 弾を人数分用意
	bulletManager = new BulletManager(playerMax);

}


// 処理
void GameManager::Proc()
{
	// 入力取得
	inputManager->Proc();

	// 移動
	for (int i = 0; i < players.size(); i++)
	{
		
	}

	// 弾の移動
	bulletManager->Move();

	// 当たり判定
	collisionManager->HitCheck_Everything(players, stageManager->GetBoxData());
}

// 描画
void GameManager::Draw()
{
	// プレイヤーたちの描画
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Draw();
	}

	// 弾の描画
	bulletManager->Draw();

	// ステージの描画
	stageManager->Draw();
}


