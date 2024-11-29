#include "../header/Player.h"

Player::~Player()
{

}

void Player::Init(BulletManager* bullet, InputManager* input)
{
	bulletManager = bullet;
	inputManager = input;
}

// プレイヤーのメイン処理
void Player::Proc()
{
	DrawFormatString(15, 5, GetColor(0, 0, 0), "[Debug]");
	// 死んでいなかったら処理をする ※isActiveがtrueのときは死んでいる
	if (status.m_isActive)
	{
		// コントローラーの状態を更新
		GetController();

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

		// 射撃を行う
		if (controller.m_RTrigger) bulletManager->AddBullet(deviceNum, status);

		// 経験値を見て強化できるか確認
		ObserveExp();

		// 強化内容をボタンで選ぶ
		ChooseBonus(InputButtonToInt());


		// 座標を更新
		// UpdatePosition();
	}

}

// コントローラー情報を更新
void Player::GetController()
{
	controller.m_LStick = inputManager->GetStick(deviceNum, Stick::LEFT);
	controller.m_RStick = inputManager->GetStick(deviceNum, Stick::RIGHT);
	controller.m_LTrigger = inputManager->GetButton(deviceNum, Button::LEFT_TRIGGER);
	controller.m_RTrigger = inputManager->GetButton(deviceNum, Button::RIGHT_TRIGGER);
}

// コントローラーで入力されたXYABボタンをint型で返す
int Player::InputButtonToInt()
{
	int value = (int)Cardinal::MAX;

	if (inputManager->CheckDownButton(deviceNum, Button::X)) value = (int)Cardinal::WEST;
	else if (inputManager->CheckDownButton(deviceNum, Button::Y)) value = (int)Cardinal::NORTH;
	else if (inputManager->CheckDownButton(deviceNum, Button::B)) value = (int)Cardinal::EAST;
	else if (inputManager->CheckDownButton(deviceNum, Button::A)) value = (int)Cardinal::SOUTH;

	printfDx("value %d\n", value);

	return value;
}