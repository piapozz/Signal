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
			// 描画
			_bulletPram[i].m_BulletList[j].Draw();
		}
	}
}

// 発射
void BulletManager::AddBullet(int playerNum , BaseObject::Status status)
{
	// 渡されたプレイヤーの弾を一つ追加
	_bulletPram[playerNum].m_BulletList.push_back(NormalShot(_bulletPram[playerNum].m_BulletStatus, status));
}


// バレットのステータスを上げる
// 引数 上げるステータス、プレイヤーの番号、
void BulletManager::LevelUpStatus(BulletStatus status, int playerNum)
{
	// 受け取ったパラメーターを上昇
	_bulletPram[playerNum].m_BulletStatus[status]++;
}

// バレットのタイプを上げる
// 引数 追加するタイプ、プレイヤーの番号、
void BulletManager::LevelUpStatus(BulletStatus type, int playerNum)
{
	// 受け取ったタイプを上昇
	_bulletPram[playerNum].m_BulletType[type]++;
}