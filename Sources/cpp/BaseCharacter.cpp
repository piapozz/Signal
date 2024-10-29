#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
	inputManager = new InputManager();
	collisionManager = new CollisionManager();

	hitObject = false;
}

BaseCharacter::~BaseCharacter()
{
	delete inputManager;
	delete collisionManager;
}

// 通常移動処理
void BaseCharacter::Move(Vector2 moveVec)
{
	status.m_nextPosition.x = 0.0f;
	status.m_nextPosition.y = 0.0f;

	// 回避移動だったら
	if (dodgeNow)
	{
		// 向いている方向に強制的に進む
		status.m_nextPosition.x = cos(status.m_angle) * dodgeSpeed;
		status.m_nextPosition.y = sin(status.m_angle) * dodgeSpeed;
	}

	// 通常移動
	else
	{
		// 斜めに入力されていなかったら
		if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
		{
			// 移動ベクトルにスピードをかけてそのまま加算
			status.m_nextPosition.x += moveVec.x * speed;
			status.m_nextPosition.y += moveVec.y * speed;
		}

		// 斜め入力されていたら
		else
		{
			// 移動ベクトルにスピードをかけてそのまま加算
			status.m_nextPosition.x += moveVec.x * speed / 0.5f;
			status.m_nextPosition.y += moveVec.y * speed / 0.5f;
		}
	}
}

// 現在座標に適応
void BaseCharacter::UpdatePosition()
{
	// 移動予定座標とオブジェクトとの当たり判定を見て移動を完了させるか分岐（この状態では動けなくなる）
	if (hitObject != true)
	{
		// 座標を更新
		status.m_position.x += status.m_nextPosition.x;
		status.m_position.y += status.m_nextPosition.y;
	}
}

// 向きを変える
void BaseCharacter::Rotate(Vector2 stickAngle)
{
	// 移動方向から角度を計算
	if (stickAngle.x != 0.0f || stickAngle.y != 0.0f)
	{
		// 角度計算しつつ角度をラジアンで返す
		status.m_angle = atan2(stickAngle.y, stickAngle.x) * (180.0f / DX_PI_F);
	}
}

// 回避ボタンが押されたら移動方法をMoveからDodgeMoveに切り替える
void BaseCharacter::Dodge(Vector2 moveVec) { if (canDodge == true)dodgeNow = true; }

void BaseCharacter::PowerUp()
{

}

void BaseCharacter::StatusUp()
{

}