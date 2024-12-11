#include "../header/GameManager.h"

// デストラクタ
GameManager::~GameManager() 
{
	for (int i = 0; i < _pDevices.size(); i++)
	{
		delete _pDevices[i];
	}
	delete _pCollisionManager;	// 当たり判定
	delete _pStageManager;		// ステージ
	delete _pBulletManager;		// 弾
	delete _pUiManager;			// UI
	delete _pInputManager;		// 入力
}

// 初期化
void GameManager::Init()
{
	_pPlayers.push_back(new Player(_pStageManager->GetStartPos()[0], _pBulletManager));
	_pPlayers.push_back(new Player(_pStageManager->GetStartPos()[1], _pBulletManager));

	AudioManager::GetInstance().PlayLoopBGM(BGMName::IN_GAME);

	// ゲームが終了しているかを管理
	_isFinish = false;

	for (int i = 0; i < _pPlayers.size(); i++)
	{
		_pPlayers[i]->Init(_pBulletManager, _pInputManager);
		_pDevices.push_back(_pPlayers[i]);
	}

	for (int i = 0; i < _pEnemys.size(); i++)
	{
		_pEnemys[i]->Init(_pBulletManager, _pDevices, _pCollisionManager, _pStageManager);
		_pDevices.push_back(_pEnemys[i]);
	}

	_pCollisionManager->Init(_pDevices, _pStageManager->GetBoxData(), _pBulletManager);
	
	// プレイヤーの設定
	for (int i = 0; i < _pDevices.size(); i++)
	{
		BaseCharacter* device = _pDevices[i];
		// デバイスごとに番号をつける
		device->deviceNum = i;

		// プレイヤーだったらどのコントローラーを使うかを割り当てる
		if (device->GetIsPlayer() == true)
		{
			// 割り当て
			device->SetPlayerNum(i);
			// プレイヤー用のイメージを設定
			device->SetImageData(PLAYER_GRAPH_ADRESS[i].c_str());
		}
		//else
		//{
		//	// 敵用のイメージを設定
		//	device->SetImageData("Resources/Signal_Enemy.png");
		//}
	}

	_pUiManager->Init(_pBulletManager, _pDevices);
}
// 処理
void GameManager::Proc()
{
	// 入力取得
	_pInputManager->Proc();

	for (int i = 0; i < _pDevices.size(); i++)
	{
		_pDevices[i]->Proc();
	}

	// 弾の移動
	_pBulletManager->Move();

	// 爆発の生成
	_pBulletManager->CreateExplosion();

	// 当たり判定
	_pCollisionManager->HitCheck_Everything();
	_pCollisionManager->UpdateHitObj();

	// 座標を更新
	for (int i = 0; i < _pDevices.size(); i++)
	{
		_pDevices[i]->UpdatePosition();
	}

	// 弾の座標更新
	_pBulletManager->UpdatePosition();

	_pStageManager->Proc();

	// 終了確認
	CheckFinish();
}

// 描画
void GameManager::Draw()
{
	// ステージの描画
	_pStageManager->Draw();

	// 弾の描画
	_pBulletManager->Draw();

	// プレイヤーたちの描画
	for (int i = 0; i < _pDevices.size(); i++)
	{
		if (_pDevices[i]->status.m_isActive != false)_pDevices[i]->Draw();

		_pUiManager->Draw();
	}
}

// 終了確認
void GameManager::CheckFinish()
{
	// 死亡確認
	std::vector<int> activeDevice;
	for (int i = 0; i < _pDevices.size(); i++)
	{
		// 死亡させる
		_pDevices[i]->SetSurvival();

		// 死亡しているか確認
		if (_pDevices[i]->GetActive())
			// 死亡していなかったら追加
			activeDevice.push_back(i);
	}

	// アクティブなキャラが1以下なら
	if (activeDevice.size() <= 1)
	{
		// 配列の0番目にいるプレイヤーを勝者にする
		Memory::GetInstance().winner = activeDevice[0] + 1;

		// ゲームを終了
		_isFinish = true;
	}
}

bool GameManager::GetFinish()
{
	return _isFinish;
}