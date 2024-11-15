#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

	hitObject = false;
	dodgeNow = false;

	exp = 0;
	request = 3;
	// speed = 1.0f;
}

BaseCharacter::~BaseCharacter()
{

}

// 通常移動処理
void BaseCharacter::Move()
{
	// 回避移動だったら
	if (dodgeNow)
	{
		// 向いている方向に強制的に進む
		status.m_nextPosition.x = (status.m_position.x + cos(status.m_angle)) * dodgeSpeed;
		status.m_nextPosition.y = (status.m_position.y + sin(status.m_angle)) * dodgeSpeed;
	}

	// 通常移動
	else
	{
		if (moveVec.x != 0.0f || moveVec.y != 0.0f)
		{
			// 移動ベクトルの長さを計算
			vecLength = sqrt(pow(moveVec.x, 2.0f) + pow(moveVec.y, 2.0f));

			// 正規化された移動ベクトルにスピードをかけて次の位置を計算
			status.m_nextPosition.x = status.m_position.x + (moveVec.x / vecLength);
			status.m_nextPosition.y = status.m_position.y + (moveVec.y / vecLength);
		}
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

// プレイヤーに番号を振り分け
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// 引数でもらった番号をプレイヤー番号に設定
	playerNum = playerNumber;
}

void BaseCharacter::LevelUp()
{
	// レベルアップに必要な個数を満たしていたら
	if (GetExpValue() >= request)
	{
		// レベルアップしたら次のレベルアップに必要なコストを上げる
		request += 3;

		// 三の倍数回これまでにレベルアップしていたらパワーアップから選ぶ
		if (levelUpCount % 3)
		{
			// パワーアップできる回数を一あげる
			powerUpCount++;

		}

		// 三の倍数回ではなかったらステータスから選ぶ
		else
		{
			// ステータスアップできる回数を一あげる
			statusUpCount++;

		}
	}

	// レベルアップできる回数を見てコントローラーの入力を受け取り結果を反映させる
	// パワーアップを行う
	if (powerUpCount)
	{

		PowerUp();
	}

	// ステータスアップを行う
	else if (statusUpCount)
	{

		StatusUp();
	}
}

// 選択肢を
void BaseCharacter::PowerUp()
{
	// 重複しないように選択肢配列の中身を抽選
	// 選択肢配列の中身を抽選するfor文
	for (int i = 0; 0 < CHOICE_POWER_MAX; i++)
	{
		// 他の中身と重複していないかを確認する
		for (int j = 0; 0 < CHOICE_POWER_MAX; j++)
		{
			// 重複しなくなるまで無限ループ
			while (choicePower[i] != choicePower[j])
			{
				// 列挙体BulletTypeの大きさを使って乱数を取得し選択肢配列に代入
				choicePower[i] = GetRand((int)BulletType::MAX);
			}
		}
	}

	// MAXをのぞいた可変長配列の初期化
	for (int i = 0; 0 < (int)BulletType::MAX - 1; i++)
	{
		// 可変長配列に要素を追加
		choicePower.push_back(i);
	}

	// BulletType::NORMALを削除 （begin() で戦闘を削除）
	choicePower.erase(choicePower.begin());

	// 現在の配列の大きさから表示させたい分を引いて、取り除きたい分for文を回す
	for (int i = 0; i < choicePower.size() - CHOICE_POWER_MAX; i++)
	{
		auto it = std::find(choicePower.begin(), choicePower.end(), GetRand(choicePower.size()));

		// 配列の要素数を使って乱数を取得してそのまま配列の要素を削除
		choicePower.erase(it);
	}
}

// ステータスアップを行う
void BaseCharacter::StatusUp()
{
	// 重複しないように選択肢配列の中身を抽選
	// 選択肢配列の中身を抽選するfor文
	for (int i = 0; 0 < CHOICE_STATUS_MAX; i++)
	{
		// 他の中身と重複していないかを確認する
		for (int j = 0; 0 < CHOICE_STATUS_MAX; j++)
		{
			// 重複しなくなるまで無限ループ
			while (choiceStatus[i] != choiceStatus[j])
			{
				// 列挙体BulletTypeの大きさを使って乱数を取得し選択肢配列に代入
				choiceStatus[i] = GetRand((int)BulletStatus::MAX);
			}
		}
	}
}

// 回避ボタンが押されたら移動方法をMoveからDodgeMoveに切り替える
void BaseCharacter::Dodge() { if (canDodge == true)dodgeNow = true; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

void BaseCharacter::GainExp(int expValue) { exp += expValue; }

int BaseCharacter::GetExpValue() { return exp; }
