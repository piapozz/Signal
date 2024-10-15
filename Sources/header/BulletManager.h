#pragma once

#include <vector>
#include "BaseBullet.h"

#include "NormalShot.h"

using namespace std;

class BulletManager
{
public:
	// プレイヤーごとに持つ弾の情報
	typedef struct BulletPram
	{
		float m_BulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
		int m_BulletType[(int)BulletType::MAX] = { 1,0,0,0,0,0 };
		std::vector<BaseBullet> m_BulletList;
	};

private:

	std::vector<BulletPram> _bulletPram;

	float m_Rate = 1.0f;	// 発射間隔

public:


	// コンストラクタ
	BulletManager();
	BulletManager(int playerNum);

	// デストラクタ
	~BulletManager();

	// 弾の移動
	void Move();

	// 描画
	void Draw();

	// 発射
	void AddBullet(int playerNum , BaseObject::Status status);

	// バレットのステータスを上げる
	// 引数 上げるステータス、プレイヤーの番号、
	void LevelUpStatus(BulletStatus status , int playerNum);

	// バレットのタイプを上げる
	// 引数 追加するタイプ、プレイヤーの番号、
	void LevelUpType(BulletType type, int playerNum);
};