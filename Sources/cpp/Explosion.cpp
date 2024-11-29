#include "../header/Explosion.h"


Explosion::Explosion() 
{
	// 時間の初期化
	_time = GetNowCount();
	objectHandle = LoadGraph("Resources/Enemy.png");
}

Explosion::Explosion(BaseChamber::ExplosionContainer container, Status objStatus)
{
	// 情報、ステータス、時間の初期化
	_time = GetNowCount();
	_explosionContainer = container;
	status = objStatus;
	status.m_isActive = true;
	damage = 3;
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
	if (GetNowCount() - _time  > _explosionContainer.time * 60)
		status.m_isActive = false;
}