#pragma once

#include <vector>
#include "BaseChamber.h"

#include "NormalChamber..h"

using namespace std;

class BulletManager
{
public:
	// プレイヤーごとに持つ弾の情報
	typedef struct BulletPram
	{
		float m_BulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
		int m_BulletType[(int)BulletType::MAX] = { 1,0,0,0,0,0 };
		std::vector<BaseChamber> m_BulletList;
	};



private:

	const float RATE_VALUE = 0.2f;	// 一レベルごとに上がっていくレート

	int _diffusion = 2;				// 拡散のレベル一ごとに増える弾の数
	int _diffusionAngleMax = 120;	// 拡散する角度
	float time = 0;					// 現在の秒数

public:

	static std::vector<BulletPram> _bulletPram;

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