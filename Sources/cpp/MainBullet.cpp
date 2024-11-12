#include "../header/MainBullet.h"

MainBullet::MainBullet()
{
	// �^����ꂽ�^�C�v�A�X�e�[�^�X�̏������ƂɍŏI�I�ȃX�e�[�^�X�Ɖ摜���o��
	_normalChanber = new NormalChamber(&status, &_bulletContainer);

	status.m_isActive = false;
}

MainBullet::~MainBullet()
{

}

// �p�x�C��
void MainBullet::UpdateAngle()
{
	// ���˂̊p�x�␳

	// �U���̊p�x�C��

}

// �ړ�
void MainBullet::Move()
{
	// �ʏ�̈ړ�
	_normalChanber->Move();
}

// ���e��
void MainBullet::Impact()
{
	// �ђʂ̒��e

	// ���˂̒��e

	Destroy();

}

// ���Ŏ�
void MainBullet::Destroy()
{
	// �����̏��Ŏ�


	// �g�p���I���
	status.m_isActive = false;
}

// �˒��Ǘ��֐�
void MainBullet::CheckRange()
{
	// ���̍��W���狗�����o���đ����Ă���
	_distance += Vector2::Distance(status.m_nextPosition, status.m_position);

	if (_distance < _bulletContainer.mainContainer.m_Range) return;

	Destroy();
}

// ���W�A�p�x�A�X�e�[�^�X�Z�b�g
void MainBullet::Reload(Status objStatus, float Pram[], int type[])
{
	status = objStatus;

	for (int i = 0; i < (int)BulletStatus::MAX; i++) 
	{
		_bulletStatus[i] = Pram[i];
	}

	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		_bulletType[i] = type[i];
	}

	// �g�p��
	status.m_isActive = true;
	_distance = 0;
}

// �X�e�[�^�X�̃��x���ɂ���Ēl������������
void MainBullet::UpdateStatus()
{
	_bulletContainer.mainContainer.m_Speed = _bulletType[(int)BulletStatus::SPEED] * 5;
	_bulletContainer.mainContainer.m_Range = _bulletType[(int)BulletStatus::RANGE] * 300;
	damage = _bulletType[(int)BulletStatus::POWER] * 1;
}