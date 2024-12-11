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

// 敵の挙動
void Enemy::Proc()
{
	Vector2 pos = status.m_position;
	Vector2 targetPos = _targetObj->status.m_position;
	// 標的との間に障害物があるか標的が非アクティブになったら
	if (!_targetObj->GetActive() || !_pCollisionManager->CheckHitRay(pos, targetPos))
	{
		// ターゲットを変更
		SetTarget();
		targetPos = _targetObj->status.m_position;
	}

	// 標的との距離を求める
	float targetDistance = Vector2::Distance(targetPos, pos);

	// 標的の方向を向く
	Vector2 angleDir = Vector2::Normalize(targetPos - pos);
	Rotate(angleDir);

	// 移動量を決める
	moveVec = Vector2(0, 0);
	if (targetDistance > BOX_SIZE * 3)
		moveVec = angleDir;
	else if (targetDistance < BOX_SIZE)
		moveVec = angleDir * (-1);

	Move();

	// 射撃
	_pBulletManager->AddBullet(deviceNum, status);

	// パワーアップの選択
	//SelectPowerUp();
}

void Enemy::SetTarget()
{
	// BaseObjectを継承しているオブジェクトのリスト
	std::vector<BaseObject*> objectList;

	// 射線の通っているプレイヤーを標的にする
	Vector2 pos = status.m_position;
	std::vector<BaseCharacter*> playerList;

	for (int i = 0; i < _pPlayers.size(); i++)
	{
		BaseCharacter* player = _pPlayers[i];
		Vector2 targetPos = player->status.m_position;

		// 間にオブジェクトがないか判定
		if (_pCollisionManager->CheckHitRay(pos, targetPos))
			playerList.push_back(player);
	}

	// 射線上にプレイヤーがいるか
	if (playerList.size() > 0)
	{
		_targetObj = playerList[0];
		float nearDistance = Vector2::Distance(pos, _targetObj->status.m_position);
		// 距離が近いプレイヤーを標的にする
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
	// プレイヤーがいないなら
	else
	{
		// 一番近くの箱を標的にする
		_targetObj = _pStageManager->GetNearBox(pos);
	}
}

void Enemy::SelectPowerUp()
{
	int randNum = GetRand(3);
	ChooseBonus(randNum);
}