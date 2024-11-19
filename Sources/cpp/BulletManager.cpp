#include "../header/BulletManager.h"

// コンストラクタ
BulletManager::BulletManager() 
{

}

// コンストラクタ
BulletManager::BulletManager(int playerNum)
{
	for (int i = 0; i < playerNum; i++) 
	{
		_bulletPram.push_back(BulletPram());
		_bulletPram[i].time = GetNowCount();

		for (int j = 0; j < BULLET_MAX; j++) 
		{
			_bulletPram[i].m_BulletList.push_back(new MainBullet());
			_bulletPram[i].m_ExplosionList.push_back(new Explosion());
			_bulletPram[i].m_BulletList[j]->SetActive(false);
		}
	}
}

// デストラクタ
BulletManager::~BulletManager()
{
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < BULLET_MAX; j++)
		{
			delete _bulletPram[i].m_BulletList[j];
		}
	}
}

// 弾の移動
void BulletManager::Move() 
{
	// プレイヤーとそれぞれの弾の分繰り返して移動する
	for (int i = 0; i < _bulletPram.size(); i++) 
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++) 
		{
			// 有効判定
			// 移動
			if (_bulletPram[i].m_BulletList[j]->GetActive())
				_bulletPram[i].m_BulletList[j]->Move();

			// 爆発物の移動、拡縮
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->Move();
		}
	}
}

// 描画
void BulletManager::Draw()
{
	int count = 0;

	// プレイヤーとそれぞれの弾の分繰り返して移動する
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// 有効判定
			// 描画
			if (_bulletPram[i].m_BulletList[j]->GetActive())
				_bulletPram[i].m_BulletList[j]->Draw();

			// 爆発物の描画
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->Draw();

			//count++;
		}
	}

	//printfDx("\n%d / %d\n", count , BULLET_MAX * _bulletPram.size());
}

// 座標更新
void BulletManager::UpdatePosition()
{
	// プレイヤーとそれぞれの弾の分繰り返して座標更新する
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// 爆発物の経過時間チェック
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->Move();

			// 有効判定
			if (!_bulletPram[i].m_BulletList[j]->GetActive()) continue;

			// 更新
			_bulletPram[i].m_BulletList[j]->UpdatePosition();

			// 射程管理
			_bulletPram[i].m_BulletList[j]->CheckRange();
		}
	}
}

/// <summary>
/// バレットリストに現在のステータスの弾を追加する
/// </summary>
/// <param name="playerNum">プレイヤー番号</param>
/// <param name="status">弾を発射する座標と角度</param>
void BulletManager::AddBullet(int playerNum , BaseObject::Status status)
{
	// Rate計算

	float interval = 1 + (_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::RATE] * RATE_VALUE);

	if (GetNowCount() - _bulletPram[playerNum].time < interval) return;

	_bulletPram[playerNum].time = GetNowCount();

	// 拡散のパラメーターがあった場合複数方向に向けて発射する
	if (_bulletPram[playerNum].m_BulletType[(int)BulletType::MULTI_SHOT] == 0)
	{
		// 渡されたプレイヤーの弾を一つ追加
		//_bulletPram[playerNum].m_BulletList.push_back(NormalChamber(_bulletPram[playerNum].m_BulletStatus, status));
		for (int i = 0; i < _bulletPram[playerNum].m_BulletList.size(); i++) 
		{
			if (_bulletPram[playerNum].m_BulletList[i]->GetActive()) continue;

			// 使える弾を見つけた
			_bulletPram[playerNum].m_BulletList[i]->Reload(status, _bulletPram[playerNum].m_BulletStatus, _bulletPram[playerNum].m_BulletType);

			break;
		}
	}
	else 
	{
		// レベルを格納
		int level = _bulletPram[playerNum].m_BulletType[(int)BulletType::MULTI_SHOT];

		// 間隔を算出
		float rate = _diffusionAngleMax / ((_diffusion * level) + 1);

		// ラジアンに変換
		float radianAngle = rate;

		// 発射ステータスを作成
		BaseObject::Status temp = status;
		temp.m_angle -= radianAngle * ((_diffusion * level) / 2);

		// それぞれの角度に対して弾を発射
		for (int i = 0; i < ((_diffusion * level) + 1); i++)
		{
			// 現在の角度に応じて弾の発射ステータスを調整
			temp.m_angle = status.m_angle - radianAngle * ((_diffusion * level) / 2) + radianAngle * i;

			// 使える弾を探してリロード
			for (int j = 0; j < _bulletPram[playerNum].m_BulletList.size(); j++)
			{
				if (_bulletPram[playerNum].m_BulletList[j]->GetActive()) continue;
				
				// 使える弾を見つけた
				_bulletPram[playerNum].m_BulletList[j]->Reload(temp, _bulletPram[playerNum].m_BulletStatus, _bulletPram[playerNum].m_BulletType);
				break;
			}
		}
	}
}


// バレットのステータスを上げる
// 引数 上げるステータス、プレイヤーの番号、
void BulletManager::LevelUpStatus(BulletStatus status, int playerNum)
{
	// 受け取ったパラメーターを上昇
	_bulletPram[playerNum].m_BulletStatus[(int)status]++;
}

// バレットのタイプを上げる
// 引数 追加するタイプ、プレイヤーの番号、
void BulletManager::LevelUpType(BulletType type, int playerNum)
{
	// 受け取ったタイプを上昇
	_bulletPram[playerNum].m_BulletType[(int)type]++;
}