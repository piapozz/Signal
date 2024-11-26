#include "../header/Explosion.h"


Explosion::Explosion() 
{
	// 時間の初期化
	_time = (float)GetNowCount();
	objectHandle = LoadGraph("Resources/Enemy.png");
}

Explosion::Explosion(BaseChamber::ExplosionContainer container, Status objStatus)
{
	// 情報、ステータス、時間の初期化
	_time = (float)GetNowCount();
	_explosionContainer = container;
	status = objStatus;
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
	if (_time - GetNowCount() > _explosionContainer.time) status.m_isActive = false;
}