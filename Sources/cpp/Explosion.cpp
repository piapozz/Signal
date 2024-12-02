#include "../header/Explosion.h"


Explosion::Explosion() 
{
	// ���Ԃ̏�����
	_time = GetNowCount();
	objectHandle = LoadGraph("Resources/Bomb.png");
}

Explosion::Explosion(BaseChamber::ExplosionContainer container, Status objStatus)
{
	// ���A�X�e�[�^�X�A���Ԃ̏�����
	_time = GetNowCount();
	_explosionContainer = container;
	status = objStatus;
	status.m_isActive = true;
	damage = 5;
	objectHandle = LoadGraph("Resources/Bomb.png");
}

Explosion::~Explosion()
{

}

// �����̖c��
void Explosion::Move()
{
	status.m_shapeSize += _explosionContainer.expansionRange;
}

// �o�ߎ��Ԃ̃`�F�b�N
void Explosion::CheckExplosionTimeOver()
{
	// �o�ߎ��Ԃ��߂��Ă�����g�p���I���
	if (GetNowCount() - _time  > _explosionContainer.time * 60)
		status.m_isActive = false;
}