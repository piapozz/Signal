#include "../header/Explosion.h"


Explosion::Explosion() 
{
	// ���Ԃ̏�����
	_time = (float)GetNowCount();
	objectHandle = LoadGraph("Resources/Enemy.png");
}

Explosion::Explosion(BaseChamber::ExplosionContainer container, Status objStatus)
{
	// ���A�X�e�[�^�X�A���Ԃ̏�����
	_time = (float)GetNowCount();
	_explosionContainer = container;
	status = objStatus;
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
	if (_time - GetNowCount() > _explosionContainer.time) status.m_isActive = false;
}