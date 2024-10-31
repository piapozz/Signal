#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

	hitObject = false;
	dodgeNow = false;

	speed = 1.0f;
}

BaseCharacter::~BaseCharacter()
{

}

// 通常移動処理
void BaseCharacter::Move()
{
	printfDx("moveVec.x%f\n", moveVec.x);
	printfDx("moveVec.y%f\n", moveVec.y);

	// status.m_nextPosition.x = 0.0f;
	// status.m_nextPosition.y = 0.0f;

	// 回避移動だったら
	if (dodgeNow)
	{
		// 向いている方向に強制的に進む
		status.m_nextPosition.x = status.m_position.x + cos(status.m_angle) * dodgeSpeed;
		status.m_nextPosition.y = status.m_position.y + sin(status.m_angle) * dodgeSpeed;
	}

	// 通常移動
	else
	{
		// 斜めに入力されていなかったら
		if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
		{
			// 移動ベクトルにスピードをかけてそのまま加算
			status.m_nextPosition.x = status.m_position.x + moveVec.x * speed;
			status.m_nextPosition.y = status.m_position.y + moveVec.y * speed;
		}

		// 斜め入力されていたら
		else
		{
			// 移動ベクトルにスピードをかけてそのまま加算
			status.m_nextPosition.x = status.m_position.x + moveVec.x * speed / 0.5f;
			status.m_nextPosition.y = status.m_position.y + moveVec.y * speed / 0.5f;
		}
	}
}

// 向きを変える
void BaseCharacter::Rotate(Vector2 stickAngle)
{
	// 移動方向から角度を計算
	//if (stickAngle.x != 0.0f || stickAngle.y != 0.0f)
	{
		// 角度計算しつつ角度をラジアンで返す
		status.m_angle = atan2(stickAngle.y, stickAngle.x) * (180.0f / DX_PI_F);
	}
}

// プレイヤーに番号を振り分け
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// 引数でもらった番号をプレイヤー番号に設定
	playerNum = playerNumber;
}

// 回避ボタンが押されたら移動方法をMoveからDodgeMoveに切り替える
void BaseCharacter::Dodge() { if (canDodge == true)dodgeNow = true; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}