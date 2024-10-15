#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

BaseCharacter::~BaseCharacter()
{

}

// 通常移動処理
void BaseCharacter::Move(Vector2 moveVec, float angle)
{
	// 移動後の予定座標
	Vector2 temp;

	// 斜めに入力されていなかったら
	if (moveVec.x != 0.0f && moveVec.y == 0.0f || moveVec.x == 0.0f && moveVec.y != 0.0f)
	{
		if (moveVec.x >= 0) temp.x += moveVec.x * speed;
		if (moveVec.x <= 0) temp.x -= moveVec.x * speed;
		if (moveVec.y >= 0) temp.y += moveVec.y * speed;
		if (moveVec.y <= 0) temp.y -= moveVec.y * speed;
	}

	// 斜め入力されていたら
	else
	{
		if (moveVec.x >= 0 && moveVec.y >= 0) temp.x += moveVec.x * speed;
		if (moveVec.x <= 0 && moveVec.y >= 0) temp.x -= moveVec.x * speed;
		if (moveVec.x >= 0 && moveVec.y <= 0) temp.y += moveVec.y * speed;
		if (moveVec.x <= 0 && moveVec.y <= 0) temp.y -= moveVec.y * speed;
	}
	// 移動予定座標とオブジェクトとの当たり判定を見て移動を完了させるか分岐
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
	// 方向入力に従ってキャラクターを移動
	if (stickAngle.x != 0.0f || stickAngle.y != 0.0f)
	{	
		
	}
}

void BaseCharacter::Shot()
{

}

void BaseCharacter::Dodge(Vector2 moveVec, float angle)
{
	// 移動方向に向かって回避を実装
	if (moveVec.x != 0.0f || moveVec.y != 0.0f)
	{
		// 計算用のVECTOR変数
		Vector2 temp;

		float sinParam = sinf(angle / 180.0f * DX_PI_F);
		float cosParam = cosf(angle / 180.0f * DX_PI_F);


		temp.x = moveVec.x * cosParam - moveVec.y * sinParam * 2.0f;
		temp.y = moveVec.x * sinParam + moveVec.y * cosParam * 2.0f;

		// 当たり判定によって自身の場所を更新するかを決める
	}
}

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