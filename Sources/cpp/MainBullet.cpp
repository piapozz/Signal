#include "../header/MainBullet.h"

MainBullet::MainBullet()
{
	// �^����ꂽ�^�C�v�A�X�e�[�^�X�̏������ƂɍŏI�I�ȃX�e�[�^�X�Ɖ摜���o��
	normalChanber = new NormalChamber(&status, &_mainContainer);
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
	normalChanber->Move();
}

// ���e��
void MainBullet::Impact()
{
	// �ђʂ̒��e

	// ���˂̒��e

}

// ���Ŏ�
void MainBullet::Destroy()
{
	// �����̏��Ŏ�


	// �g�p���I���
	_mainContainer.m_Flag = false;
}


// ���W�X�V
void UpdatePosition() 
{

}

// �`��֐�
void MainBullet::Draw()
{
	// ��]�g�k�`��
	//DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, DX_PI / 180 * status.m_angle, graph, TRUE);
}

// ���W�X�V
void MainBullet::UpdatePosition()
{
	status.m_position = status.m_nextPosition;
}

// �˒��Ǘ��֐�
void MainBullet::CheckRange()
{
	// ���̍��W���狗�����o���đ����Ă���
	distance += Vector2::Distance(status.m_nextPosition, status.m_position);

	if (distance < _mainContainer.m_Range) return;

	Destroy();
}

// ���W�A�p�x�A�X�e�[�^�X�Z�b�g
void MainBullet::Reload(Status objStatus, float Pram[], int type[])
{
	status = objStatus;

	for (int i = 0; i < (int)BulletStatus::MAX; i++) 
	{
		bulletStatus[i] = Pram[i];
	}

	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		bulletType[i] = type[i];
	}

	// �g�p��
	_mainContainer.m_Flag = true;
}