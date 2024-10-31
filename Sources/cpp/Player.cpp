#include "../header/Player.h"

Player::Player(Vector2 pos)
{
	status.m_position = pos;
	status.m_nextPosition = pos;

	// プレイヤーの生存状況
	isDead = false;
	canMove = true;

	isPlayer = true;
}

Player::~Player()
{

}

// プレイヤーのメイン処理
void Player::Proc(BulletManager* bullet, InputManager* inputManager)
{
	
	// 死んでいなかったら処理をする ※isDeadがtrueのときは死んでいる
	// if (isDead != true)
	{
		// コントローラーの状態を更新
		GetController(inputManager);

		moveVec = controller.m_LStick;

		// 回避が押されていたら回避する
		if (controller.m_LTrigger)Dodge();
		
		// もし移動できる状態だったら
		if (canMove)
		{
			// 回避移動状態ではなかったら通常移動をする回避状態だったら回避する
			Move();
		}

		// プレイヤーの向きを変更
		Rotate(controller.m_RStick);

		if (controller.m_RTrigger) bullet->AddBullet(deviceNum, status);

		// 座標を更新
		// UpdatePosition();
	}

	// 体力が0になったときプレイヤーは死にます
	if (status.m_life <= 0) isDead = true;
	
}

// コントローラー情報を更新
void Player::GetController(InputManager* inputManager)
{
	controller.m_LStick = inputManager->GetStick(deviceNum, Stick::LEFT);
	controller.m_RStick = inputManager->GetStick(deviceNum, Stick::RIGHT);
	controller.m_LTrigger = inputManager->GetButton(deviceNum, Button::LEFT_TRIGGER);
	controller.m_RTrigger = inputManager->GetButton(deviceNum, Button::RIGHT_TRIGGER);
}