#include "../header/MainBullet.h"

MainBullet::MainBullet()
{
	_bulletContainer = new BaseChamber::BulletContainer();

	// �^����ꂽ�^�C�v�A�X�e�[�^�X�̏������ƂɍŏI�I�ȃX�e�[�^�X�Ɖ摜���o��
	_chambers[(int)BulletType::NORMAL] = new NormalChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::EXPLOSION] = new ExplosionChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::PENETRATION] = new PenetrationChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::REFLECTION] = new ReflectionChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::TRACKING_SHOT] = new TrackingChamber(&status, _bulletContainer);
	_chambers[(int)BulletType::MULTI_SHOT] = new NormalChamber(&status, _bulletContainer);

	objectHandle = LoadGraph("Resources/Enemy.png");

	status.m_isActive = false;
}

MainBullet::~MainBullet()
{
	// �|�C���^�̍폜
	for (int i = 0; i < (int)BulletType::MAX; i++) 
	{
		if(_chambers[i] != nullptr) delete _chambers[i];
	}
	delete _bulletContainer;
}

// �p�x�C��
void MainBullet::UpdateAngle()
{
	// ���˂̊p�x���f
	_chambers[(int)BulletType::REFLECTION]->AngleModifying();

	// �U���̊p�x�C��
	_chambers[(int)BulletType::TRACKING_SHOT]->AngleModifying();
}

// �ړ�
void MainBullet::Move()
{
	// �ʏ�̈ړ�
	_chambers[(int)BulletType::NORMAL]->Move();
}

// ���e��
void MainBullet::Impact(ObjectType hitType)
{
	if (hitBoxObject.size() > 0 && hitType != ObjectType::PLAYER) 
	{
		Box newObj =  *hitBoxObject[hitBoxObject.size() - 1];
		BaseChamber::ReflectionContainer temp;
		temp.norm = newObj.GetNormDir(status.m_position);
		_bulletContainer->reflectionContainer = &temp;
	}
	else if(hitType != ObjectType::PLAYER)
	{
		Box newObj = *hitBoxObject[0];
		BaseChamber::ReflectionContainer temp;
		temp.norm = newObj.GetNormDir(status.m_position);
		_bulletContainer->reflectionContainer = &temp;
	}

	switch (hitType)
	{
	case ObjectType::PLAYER:
		// �ђʂ̒��e
		if (_chambers[(int)BulletType::PENETRATION]->Impact()) return;
		break;
	case ObjectType::BOX:
		// �ђʂ̒��e
		if (_chambers[(int)BulletType::PENETRATION]->Impact()) return;
		// ���˂̒��e
		if (_chambers[(int)BulletType::REFLECTION]->Impact()) return;
		break;
	case ObjectType::WALL:
		// ���˂̒��e
		if (_chambers[(int)BulletType::REFLECTION]->Impact()) return;
		break;
	default:
		break;
	}

	Destroy();

}

// ���Ŏ�
void MainBullet::Destroy()
{
	// �����̏��Ŏ�
	_chambers[(int)BulletType::EXPLOSION]->Destroy();

	// �g�p���I���
	status.m_isActive = false;
}

// �˒��Ǘ��֐�
void MainBullet::CheckRange()
{
	// ���̍��W���狗�����o���đ����Ă���
	_distance += Vector2::Distance(status.m_nextPosition, status.m_position);

	if (_distance < _bulletContainer->mainContainer->m_Range) return;

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
	UpdateStatus();
	hitBoxObject.clear();
	hitCharObject.clear();
	_bulletContainer->LevelUp(_bulletType);
}

// �X�e�[�^�X�̃��x���ɂ���Ēl������������
void MainBullet::UpdateStatus()
{
	_bulletContainer->mainContainer->m_Speed = _bulletStatus[(int)BulletStatus::SPEED] * 2;
	_bulletContainer->mainContainer->m_Range = _bulletStatus[(int)BulletStatus::RANGE] * 500;
	damage = _bulletStatus[(int)BulletStatus::POWER] * 1;
}