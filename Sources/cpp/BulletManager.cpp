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

		for (int j = 0; j < BULLET_MAX; j++) 
		{
			_bulletPram[i].m_BulletList.push_back(new MainBullet());
		}
	}

	time = GetNowCount();
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
			if (!_bulletPram[i].m_BulletList[j]->GetActive()) return;

			// 移動
			_bulletPram[i].m_BulletList[j]->Move();
		}
	}
}

// 描画
void BulletManager::Draw()
{
	// プレイヤーとそれぞれの弾の分繰り返して移動する
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// 有効判定
			if (!_bulletPram[i].m_BulletList[j]->GetActive()) return;

			// 描画
			_bulletPram[i].m_BulletList[j]->Draw();
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

	if (GetNowCount() - time < interval) return;

	time = GetNowCount();

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
		float radianAngle = rate / 180 * DX_PI;

		// 発射ステータスを作成
		BaseObject::Status temp = status;
		temp.m_angle -= radianAngle * ((_diffusion * level) / 2);

		// それぞれの角度に対して弾を発射
		for (int i = 0; i < ((_diffusion * level) + 1); i++) 
		{
			temp.m_angle += radianAngle * i;

			// 弾を追加
			//_bulletPram[playerNum].m_BulletList.push_back(NormalChamber(_bulletPram[playerNum].m_BulletStatus, temp));

			for (int i = 0; i < _bulletPram[playerNum].m_BulletList.size(); i++)
			{
				if (!_bulletPram[playerNum].m_BulletList[i]->GetActive()) continue;

				// 使える弾を見つけた
				_bulletPram[playerNum].m_BulletList[i]->Reload(status, _bulletPram[playerNum].m_BulletStatus, _bulletPram[playerNum].m_BulletType);

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