#include "../header/GameManager.h"

// コンストラクタ
GameManager::GameManager(InputManager* pInputManager)
{
	collisionManager = new CollisionManager();
	stageManager = new StageManager(collisionManager);
	players.push_back(new Player(stageManager->GetStartPos()[0], bulletManager));
	players.push_back(new Player(stageManager->GetStartPos()[1], bulletManager));
	// enemys.push_back(new Enemy(stageManager->GetStartPos()[1], bulletManager));
	uiManager = new UIManager();
	inputManager = pInputManager;
	// 弾を人数分用意
	bulletManager = new BulletManager(players.size() + enemys.size());

	AudioManager::GetInstance().PlayLoopBGM(BGMName::IN_GAME);

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
		BaseCharacter* device = devices[i];
		// デバイスごとに番号をつける
		device->deviceNum = i;

		// プレイヤーだったらどのコントローラーを使うかを割り当てる
		if (device->GetIsPlayer() == true)
		{
			// 割り当て
			device->SetPlayerNum(i);
			// プレイヤー用のイメージを設定
			device->SetImageData("Resources/Signal_Player.png");
		}
		else
		{
			// 敵用のイメージを設定
			device->SetImageData("Resources/Signal_Enemy.png");
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

	// 終了確認
	CheckFinish();
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

		uiManager->Draw();
	}

	// 弾の描画
	bulletManager->Draw();
}

// 終了確認
void GameManager::CheckFinish()
{
	// 死亡確認
	std::vector<int> activeDevice;
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->SetSurvival();
		if (devices[i]->GetActive())
			activeDevice.push_back(i);
	}
	// アクティブなキャラが1以下なら
	if (activeDevice.size() <= 1)
	{
		winDevice = activeDevice[0];
		isFinish = true;
	}
}

bool GameManager::GetFinish()
{
	return isFinish;
}