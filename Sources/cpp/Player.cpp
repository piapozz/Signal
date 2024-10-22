#include "../header/Player.h"

Player::Player()
{
	// プレイヤーの生存状況
	isDead = false;
}

Player::~Player()
{

}

// プレイヤーのメイン処理
void Player::Proc()
{
	// 死んでいなかったら処理をする ※isDeadがtrueのときは死んでいる
	if (isDead != true)
	{
		// コントローラーの状態を更新
		GetController();

		// もし移動できる状態だったら
		if (canMove)
		{
			// もし回避移動が有効になっていたら回避移動をする
			if (dodgeNow == true) DodgeMove();
			// 回避移動状態ではなかったら通常移動をする
			else Move(controller.m_LStick);
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