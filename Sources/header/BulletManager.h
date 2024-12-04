#pragma once

#include <vector>
#include "MainBullet.h"
#include "Explosion.h"

using namespace std;

class BulletManager
{
public:
	// プレイヤーごとに持つ弾の情報
	struct BulletPram
	{
		float m_BulletStatus[(int)BulletStatus::MAX] = { 1,1,1,1 };
		int m_BulletType[(int)BulletType::MAX] = { 1,0,0,0,0 };
		std::vector<MainBullet*> m_BulletList;
		std::vector<Explosion*> m_ExplosionList;
		float time = 0;
	};


private:

	std::vector<BulletPram> _bulletPram;

	const float RATE_VALUE = 100.0f;	// 一レベルごとに上がっていくレート

	const int DIFFUSION = 2;				// 拡散のレベル一ごとに増える弾の数
	const int DIFFUSION_ANGLE_MAX = 120;	// 拡散する角度
	const int BULLET_MAX = 1024;
	const int EXPLOSION_MAX = BULLET_MAX;

public:

	// コンストラクタ
	BulletManager();
	BulletManager(const int &playerNum);

	// デストラクタ
	~BulletManager();

	// 弾の移動
	void Move();

	// 描画
	void Draw();

	// 弾の座標一括更新
	void UpdatePosition();

	// 爆発の要請があるなら生成する
	void CreateExplosion();
	void CreateExplosion(const BaseObject::Status &status, const BaseChamber::ExplosionContainer &container);

	// 発射
	void AddBullet(const int &playerNum, const BaseObject::Status &status);

	// バッレットリストを取得
	inline std::vector<BulletPram> GetBulletList() const { return _bulletPram; }

	// バレットのステータスを上げる
	// 引数 上げるステータス、プレイヤーの番号、
	void LevelUpStatus(const BulletStatus &status,const int &playerNum);

	// バレットのタイプを上げる
	// 引数 追加するタイプ、プレイヤーの番号、
	void LevelUpType(const BulletType &type, const int &playerNum);
};