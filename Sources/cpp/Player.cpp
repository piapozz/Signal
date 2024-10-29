#include "../header/Player.h"

Player::Player()
{
	// プレイヤーの生存状況
	isDead = false;
	canMove = true;
}

Player::~Player()
{

}

// プレイヤーのメイン処理
void Player::Proc()
{
	// 当たり判定の更新
	UpdateHitJudge();

	// 死んでいなかったら処理をする ※isDeadがtrueのときは死んでいる
	if (isDead != true)
	{
		// コントローラーの状態を更新
		GetController();

		// もし移動できる状態だったら
		if (canMove)
		{
			// 回避移動状態ではなかったら通常移動をする
			Move(controller.m_LStick);
		}

		// プレイヤーの向きを変更
		Rotate(controller.m_RStick);
	}

	// 体力が0になったときプレイヤーは死にます
	if (status.m_life <= 0) isDead = true;
}

// プレイヤーに番号を振り分け
void Player::SetPlayerNum(int playerNumber)
{
	// 引数でもらった番号をプレイヤー番号に設定
	playerNum = playerNumber;
}

// コントローラー情報を更新
void Player::GetController()
{
	controller.m_LStick = inputManager->GetStick(playerNum, Stick::LEFT);
	controller.m_RStick = inputManager->GetStick(playerNum, Stick::RIGHT);
}