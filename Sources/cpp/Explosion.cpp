#include "../header/Explosion.h"


Explosion::Explosion() 
{
	// 時間の初期化
	_time = GetNowCount();
	objectHandle = LoadGraph("Resources/Bomb.png");
}

Explosion::Explosion(const BaseChamber::ExplosionContainer &container,const Status &objStatus)
{
	// 情報、ステータス、時間の初期化
	_time = GetNowCount();
	_explosionContainer = container;
	status = objStatus;
	status.m_isActive = true;
	damage = 5;
	objectHandle = LoadGraph("Resources/Bomb.png");

	drawUpScale = 0.05f;
}

Explosion::~Explosion()
{

}

// 爆発の膨張
void Explosion::Move()
{
	status.m_shapeSize += _explosionContainer.expansionRange;
}

// 経過時間のチェック
void Explosion::CheckExplosionTimeOver()
{
	// 経過時間が過ぎていたら使用を終わる
	if (GetNowCount() - _time  > _explosionContainer.time * 1000)
		status.m_isActive = false;
}