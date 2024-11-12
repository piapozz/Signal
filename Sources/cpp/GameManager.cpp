#include "../header/GameManager.h"

// コンストラクタ
GameManager::GameManager()
{
	stageManager = new StageManager();
	players.push_back(new Player(stageManager->GetStartPos()[0]));
	enemys.push_back(new Enemy(stageManager->GetStartPos()[1]));
	collisionManager = new CollisionManager();
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
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->Init(collisionManager);
		players.push_back(enemys[i]);
	}

	// 
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Init(bulletManager, inputManager, players);
	}

	collisionManager->Init(players, stageManager->GetBoxData(), bulletManager);

	uiManager->Init(bulletManager);

	// プレイヤーの数を取得
	playerMax = players.size();
	
	// プレイヤーの設定
	for (int i = 0; i < players.size(); i++)
	{
		// デバイスごとに番号をつける
		players[i]->deviceNum = i;

		// プレイヤーだったらどのコントローラーを使うかを割り当てる
		if (players[i]->GetIsPlayer() == true)
		{
			// 割り当て
			players[i]->SetPlayerNum(i);
			// プレイヤー用のイメージを設定
			players[i]->SetImageData("Resources/Player.png");
		}
		else
		{
			// 敵用のイメージを設定
			players[i]->SetImageData("Resources/Enemy.png");
		}
	}

	// 弾を人数分用意
	bulletManager = new BulletManager(playerMax);

}
// 処理
void GameManager::Proc()
{
	// 入力取得
	inputManager->Proc();

	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Proc();
	}

	// 弾の移動
	bulletManager->Move();

	// 当たり判定
	collisionManager->HitCheck_Everything();

	// 座標を更新
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->UpdatePosition();
	}

	// レベルアップ処理
	for (int i = 0; i < players.size(); i++)
	{
	
	}

	// 弾の座標更新
	bulletManager->UpdatePosition();

	stageManager->Proc();
}

// 描画
void GameManager::Draw()
{
	// ステージの描画
	stageManager->Draw();

	// プレイヤーたちの描画
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->status.m_isActive != false)players[i]->Draw();

		uiManager->Draw(i);
	}

	

	// 弾の描画
	bulletManager->Draw();

}


