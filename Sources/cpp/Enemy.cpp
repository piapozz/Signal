#include "../header/Enemy.h"
#include "../header/Player.h"

Enemy::~Enemy()
{

}

void Enemy::Init(BulletManager* bullet, const std::vector<BaseCharacter*>& players, CollisionManager* collisionManager, StageManager* stageManager)
{
	_pBulletManager = bullet;
	_pPlayers = players;
	_pCollisionManager = collisionManager;
	_pStageManager = stageManager;
	SetTarget();
}

// �G�̋���
void Enemy::Proc()
{
	Vector2 pos = status.m_position;
	Vector2 targetPos = _targetObj->status.m_position;
	// �W�I�Ƃ̊Ԃɏ�Q�������邩�W�I����A�N�e�B�u�ɂȂ�����
	if (!_targetObj->GetActive() || !_pCollisionManager->CheckHitRay(pos, targetPos))
	{
		// �^�[�Q�b�g��ύX
		SetTarget();
		targetPos = _targetObj->status.m_position;
	}

	// �W�I�Ƃ̋��������߂�
	float targetDistance = Vector2::Distance(targetPos, pos);

	// �W�I�̕���������
	Vector2 angleDir = Vector2::Normalize(targetPos - pos);
	Rotate(angleDir);

	// �ړ��ʂ����߂�
	moveVec = Vector2(0, 0);
	if (targetDistance > BOX_SIZE * 3)
		moveVec = angleDir;
	else if (targetDistance < BOX_SIZE)
		moveVec = angleDir * (-1);

	Move();

	// �ˌ�
	_pBulletManager->AddBullet(deviceNum, status);

	// �p���[�A�b�v�̑I��
	//SelectPowerUp();
}

void Enemy::SetTarget()
{
	// BaseObject���p�����Ă���I�u�W�F�N�g�̃��X�g
	std::vector<BaseObject*> objectList;

	// �ː��̒ʂ��Ă���v���C���[��W�I�ɂ���
	Vector2 pos = status.m_position;
	std::vector<BaseCharacter*> playerList;

	for (int i = 0; i < _pPlayers.size(); i++)
	{
		BaseCharacter* player = _pPlayers[i];
		Vector2 targetPos = player->status.m_position;

		// �ԂɃI�u�W�F�N�g���Ȃ�������
		if (_pCollisionManager->CheckHitRay(pos, targetPos))
			playerList.push_back(player);
	}

	// �ː���Ƀv���C���[�����邩
	if (playerList.size() > 0)
	{
		_targetObj = playerList[0];
		float nearDistance = Vector2::Distance(pos, _targetObj->status.m_position);
		// �������߂��v���C���[��W�I�ɂ���
		for (int i = 1; i < playerList.size(); i++)
		{
			float distance = Vector2::Distance(pos, _targetObj->status.m_position);
			if (nearDistance < distance)
			{
				_targetObj = playerList[i];
				nearDistance = distance;
			}
		}
	}
	// �v���C���[�����Ȃ��Ȃ�
	else
	{
		// ��ԋ߂��̔���W�I�ɂ���
		_targetObj = _pStageManager->GetNearBox(pos);
	}
}

void Enemy::SelectPowerUp()
{
	int randNum = GetRand(3);
	ChooseBonus(randNum);
}