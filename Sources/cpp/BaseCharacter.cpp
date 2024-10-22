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
	// 移動後の予定座標
	Vector2 temp;

	// 斜めに入力されていなかったら
	if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
	{
		/*
		if (moveVec.x >= 0) temp.x += moveVec.x * speed;
		if (moveVec.x <= 0) temp.x -= moveVec.x * speed;
		if (moveVec.y >= 0) temp.y += moveVec.y * speed;
		if (moveVec.y <= 0) temp.y -= moveVec.y * speed;
		*/

		// 移動ベクトルにスピードをかけてそのまま加算
		temp.x += moveVec.x * speed;
		temp.y += moveVec.y * speed;
	}

	// 斜め入力されていたら
	else
	{
		/*
		// 右上移動
		if (moveVec.x >= 0 && moveVec.y >= 0)
		{
			temp.x += moveVec.x * speed / 2.0f;
		}

		// 左上移動
		if (moveVec.x <= 0 && moveVec.y >= 0)
		{
			temp.x += moveVec.x * speed / 2.0f;
		}

		// 右下移動
		if (moveVec.x >= 0 && moveVec.y <= 0)
		{
			temp.y += moveVec.y * speed;
		}

		// 左下移動
		if (moveVec.x <= 0 && moveVec.y <= 0)
		{
			temp.y += moveVec.y * speed;
		}
		*/

		// 移動ベクトルにスピードをかけてそのまま加算
		temp.x += moveVec.x * speed / 0.5f;
		temp.y += moveVec.y * speed / 0.5f;
	}

	// 移動予定座標とオブジェクトとの当たり判定を見て移動を完了させるか分岐
	if (hitObject != true)
	{
		// 座標を更新
		status.m_position.x += temp.x;
		status.m_position.y += temp.y;
	}
}

// 回避移動の処理
void BaseCharacter::DodgeMove()
{
	Vector2 temp;

	// 向いている方向に強制的に進む
	temp.x = cos(status.m_angle) * dodgeSpeed;
	temp.y = sin(status.m_angle) * dodgeSpeed;

	// 移動予定座標がオブジェクトにあたっていなかったら
	if (hitObject != true)
	{
		// 座標を更新
		status.m_position.x += temp.x;
		status.m_position.y += temp.y;
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
	// hitObject = オブジェクトと比較する関数
	// hitBullet = 弾と比較する関数
}