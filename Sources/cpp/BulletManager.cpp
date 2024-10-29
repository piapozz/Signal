#include "../header/BulletManager.h"

// コンストラクタ
BulletManager::BulletManager() 
{

}


// コンストラクタ
BulletManager::BulletManager(int playerNum)
{

}


// コンストラクタ
BulletManager::~BulletManager()
{

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
			if (!_bulletPram[i].m_BulletList[j].CheckActive()) return;

			// 移動
			_bulletPram[i].m_BulletList[j].Move();
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
			if (!_bulletPram[i].m_BulletList[j].CheckActive()) return;

			// 描画
			_bulletPram[i].m_BulletList[j].Draw();
		}
	}
}

// 発射
void BulletManager::AddBullet(int playerNum , BaseObject::Status status)
{
	// Rate計算
	time += GetNowCount();

	float interval = 1 + (_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::RATE] * RATE_VALUE);

	if (time < interval) return;

	time = 0;

	// 拡散のパラメーターがあった場合複数方向に向けて発射する
	if (_bulletPram[playerNum].m_BulletType[(int)BulletType::MULTI_SHOT] == 0)
	{
		// 渡されたプレイヤーの弾を一つ追加
		_bulletPram[playerNum].m_BulletList.push_back(NormalChamber(_bulletPram[playerNum].m_BulletStatus, status));
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
			_bulletPram[playerNum].m_BulletList.push_back(NormalChamber(_bulletPram[playerNum].m_BulletStatus, temp));
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