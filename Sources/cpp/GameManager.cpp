#include "../header/GameManager.h"

// コンストラクタ
GameManager::GameManager()
{
	stageManager = new StageManager();
	players.push_back(new Player(stageManager->GetStartPos()[0], bulletManager));
	enemys.push_back(new Enemy(stageManager->GetStartPos()[1], bulletManager));
	collisionManager = new CollisionManager();
	//bulletManager = new BulletManager();
	uiManager = new UIManager();
	inputManager = new InputManager();
	// 弾を人数分用意
	bulletManager = new BulletManager(players.size() + enemys.size());

	// ゲームが終了しているかを管理
	isFinish = false;
}

// デストラクタ
GameManager::~GameManager() 
{
	for (int i = 0; i < devices.size(); i++)
	{
		delete devices[i];
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
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Init(bulletManager, inputManager);
		devices.push_back(players[i]);
	}

	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->Init(bulletManager, devices, collisionManager, stageManager);
		devices.push_back(enemys[i]);
	}

	collisionManager->Init(devices, stageManager->GetBoxData(), bulletManager);

	// プレイヤーの数を取得
	playerMax = devices.size();
	
	// プレイヤーの設定
	for (int i = 0; i < devices.size(); i++)
	{
		// デバイスごとに番号をつける
		devices[i]->deviceNum = i;

		// プレイヤーだったらどのコントローラーを使うかを割り当てる
		if (devices[i]->GetIsPlayer() == true)
		{
			// 割り当て
			devices[i]->SetPlayerNum(i);
			// プレイヤー用のイメージを設定
			devices[i]->SetImageData("Resources/Signal_Player.png");
		}
		else
		{
			// 敵用のイメージを設定
			devices[i]->SetImageData("Resources/Signal_Enemy.png");
		}
	}

	uiManager->Init(bulletManager, devices);
}
// 処理
void GameManager::Proc()
{
	// 入力取得
	inputManager->Proc();

	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->Proc();
	}

	// 弾の移動
	bulletManager->Move();

	// 爆発の生成
	bulletManager->CreateExplosion();

	// 当たり判定
	collisionManager->HitCheck_Everything();
	collisionManager->UpdateHitObj();

	// 座標を更新
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->UpdatePosition();
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
	for (int i = 0; i < devices.size(); i++)
	{
		if (devices[i]->status.m_isActive != false)devices[i]->Draw();

		// uiManager->Draw(i);

		uiManager->Draw();


	}

	// 弾の描画
	bulletManager->Draw();

}

bool GameManager::CheckFinish() { return isFinish; }
