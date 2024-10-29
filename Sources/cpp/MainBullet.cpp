#include "../header/MainBullet.h"

MainBullet::MainBullet()
{
	// 与えられたタイプ、ステータスの情報をもとに最終的なステータスと画像を出す
	normalChanber = new NormalChamber(&status, &_mainContainer);
}

MainBullet::~MainBullet()
{

}

// 角度修正
void MainBullet::UpdateAngle()
{
	// 反射の角度補正

	// 誘導の角度修正

}

// 移動
void MainBullet::Move()
{
	// 通常の移動
	normalChanber->Move();
}

// 着弾時
void MainBullet::Impact()
{
	// 貫通の着弾

	// 反射の着弾

}

// 消滅時
void MainBullet::Destroy()
{
	// 爆発の消滅時


	// 使用を終わる
	_mainContainer.m_Flag = false;
}


// 座標更新
void UpdatePosition() 
{

}

// 描画関数
void MainBullet::Draw()
{
	// 回転拡縮描画
	//DrawRotaGraph(status.m_position.x, status.m_position.y, status.m_shapeSize, DX_PI / 180 * status.m_angle, graph, TRUE);
}

// 座標更新
void MainBullet::UpdatePosition()
{
	status.m_position = status.m_nextPosition;
}

// 射程管理関数
void MainBullet::CheckRange()
{
	// 次の座標から距離を出して足していく
	distance += Vector2::Distance(status.m_nextPosition, status.m_position);

	if (distance < _mainContainer.m_Range) return;

	Destroy();
}

// 座標、角度、ステータスセット
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

	// 使用中
	_mainContainer.m_Flag = true;
}