#include "../header/BulletManager.h"

// コンストラクタ
BulletManager::BulletManager()
{

}

// コンストラクタ
BulletManager::BulletManager(const int& playerNum)
{
	for (int i = 0; i < playerNum; i++)
	{
		_bulletPram.push_back(BulletPram());
		_bulletPram[i].time = GetNowCount();

		for (int j = 0; j < BULLET_MAX; j++)
		{
			_bulletPram[i].m_BulletList.push_back(new MainBullet(LoadGraph(BULLET_GRAPH_ADRESS[i].c_str())));
			_bulletPram[i].m_ExplosionList.push_back(new Explosion());
			_bulletPram[i].m_BulletList[j]->SetActive(false);
			_bulletPram[i].m_ExplosionList[j]->SetActive(false);
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
			delete _bulletPram[i].m_ExplosionList[j];
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
			{
				_bulletPram[i].m_BulletList[j]->Move();
				_bulletPram[i].m_BulletList[j]->UpdateAngle();
			}

			// 爆発物の移動、拡縮
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->Move();
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
			// 描画
			if (_bulletPram[i].m_BulletList[j]->GetActive())
				_bulletPram[i].m_BulletList[j]->Draw();

			// 爆発物の描画
			if (_bulletPram[i].m_ExplosionList[j]->GetActive())
				_bulletPram[i].m_ExplosionList[j]->Draw();

		}
	}
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
				_bulletPram[i].m_ExplosionList[j]->CheckExplosionTimeOver();

			// 有効判定
			if (!_bulletPram[i].m_BulletList[j]->GetActive()) continue;

			// 射程管理
			_bulletPram[i].m_BulletList[j]->CheckRange();

			// 更新
			_bulletPram[i].m_BulletList[j]->UpdatePosition();
		}
	}
}

// // 爆発の要請があるなら生成する
void BulletManager::CreateExplosion()
{
	// プレイヤーとそれぞれの弾の分繰り返して座標更新する
	for (int i = 0; i < _bulletPram.size(); i++)
	{
		for (int j = 0; j < _bulletPram[i].m_BulletList.size(); j++)
		{
			// 要請判定
			if (!_bulletPram[i].m_BulletList[j]->GetExplosion()) continue;

			// 生成
			for (int k = 0; k < _bulletPram[i].m_ExplosionList.size(); k++)
			{
				if (_bulletPram[i].m_ExplosionList[k]->GetActive()) continue;

				// 使える爆発を見つけた
				_bulletPram[i].m_ExplosionList[k] = new Explosion(_bulletPram[i].m_BulletList[j]->GetExplosionStatus(), _bulletPram[i].m_BulletList[j]->status);

				AudioManager::GetInstance().PlaySE(SEName::BOMB);

				break;
			}
		}
	}
}

// // 爆発の要請があるなら生成する
void BulletManager::CreateExplosion(const BaseObject::Status &status, const BaseChamber::ExplosionContainer &container)
{
	// 生成
	for (int i = 0; i < _bulletPram[0].m_ExplosionList.size(); i++)
	{
		if (_bulletPram[0].m_ExplosionList[i]->GetActive()) continue;

		// 使える爆発を見つけた
		_bulletPram[0].m_ExplosionList[i] = new Explosion(container, status);

		AudioManager::GetInstance().PlaySE(SEName::BOMB);

		break;
	}
}

/// <summary>
/// バレットリストに現在のステータスの弾を追加する
/// </summary>
/// <param name="playerNum">プレイヤー番号</param>
/// <param name="status">弾を発射する座標と角度</param>
void BulletManager::AddBullet(const int &playerNum, const BaseObject::Status &status)
{
	// Rate計算
	float interval = 1300 - (_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::RATE] * RATE_VALUE);

	if (GetNowCount() - _bulletPram[playerNum].time < interval) return;

	_bulletPram[playerNum].time = (float)GetNowCount();

	// 拡散のパラメーターがあった場合複数方向に向けて発射する
	if (_bulletPram[playerNum].m_BulletType[(int)BulletType::MULTI_SHOT] == 0)
	{
		// 渡されたプレイヤーの弾を一つ追加
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
		float rate = (float)(DIFFUSION_ANGLE_MAX / ((DIFFUSION * level) + 1));

		// ラジアンに変換
		float radianAngle = rate;

		// 発射ステータスを作成
		BaseObject::Status temp = status;
		temp.m_angle -= radianAngle * ((DIFFUSION * level) / 2);

		// それぞれの角度に対して弾を発射
		for (int i = 0; i < ((DIFFUSION * level) + 1); i++)
		{
			// 現在の角度に応じて弾の発射ステータスを調整
			temp.m_angle = status.m_angle - radianAngle * ((DIFFUSION * level) / 2) + radianAngle * i;

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
void BulletManager::LevelUpStatus(const BulletStatus &status, const int &playerNum)
{
	// 受け取ったパラメーターを上昇
	_bulletPram[playerNum].m_BulletStatus[(int)status]++;
}

// バレットのタイプを上げる
// 引数 追加するタイプ、プレイヤーの番号、
void BulletManager::LevelUpType(const BulletType &type,const int &playerNum)
{
	// 受け取ったタイプを上昇
	_bulletPram[playerNum].m_BulletType[(int)type]++;
}