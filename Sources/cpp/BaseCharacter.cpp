#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
	hitObject = false;
	hitBullet = false;
}

BaseCharacter::~BaseCharacter()
{

}

// 通常移動処理
void BaseCharacter::Move(Vector2 moveVec)
{
	tempPos.x = 0.0f;
	tempPos.y = 0.0f;

	// 回避移動だったら
	if (dodgeNow)
	{
		// 向いている方向に強制的に進む
		tempPos.x = cos(status.m_angle) * dodgeSpeed;
		tempPos.y = sin(status.m_angle) * dodgeSpeed;
	}

	// 通常移動
	else
	{
		// 斜めに入力されていなかったら
		if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
		{
			// 移動ベクトルにスピードをかけてそのまま加算
			tempPos.x += moveVec.x * speed;
			tempPos.y += moveVec.y * speed;
		}

		// 斜め入力されていたら
		else
		{
			// 移動ベクトルにスピードをかけてそのまま加算
			tempPos.x += moveVec.x * speed / 0.5f;
			tempPos.y += moveVec.y * speed / 0.5f;
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
		status.m_position.x += tempPos.x;
		status.m_position.y += tempPos.y;
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

// プレイヤーが保持する当たり判定の情報を更新
void BaseCharacter::UpdateHitJudge()
{
	// hitObject = collisionManager->HitCheck();
	// hitBullet = collisionManager->HitCheck();
}