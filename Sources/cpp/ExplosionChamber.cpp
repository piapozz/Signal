#include "../header/ExplosionChamber.h"


// 消滅関数 
void ExplosionChamber::Destroy()
{
	// 爆発を生成
	bulletContainer->explosionContainer->active = true;
}