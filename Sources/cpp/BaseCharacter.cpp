#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

	hitObject = false;
	dodgeNow = false;

	canLottery = true;

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

// 経験値を見て
void BaseCharacter::ObserveExp()
{
	// レベルアップに必要な個数を満たしていたら
	if (GetExpValue() >= request)
	{
		// レベルアップしたら次のレベルアップに必要なコストを上げる
		request += request + 1;

		// 三の倍数回これまでにレベルアップしていたらパワーアップから選ぶ
		if (levelUpCount % 3 == 0)
		{
			// パワーアップできる回数を一あげる
			lotteryPowerCount++;
		}

		// 三の倍数回ではなかったらステータスから選ぶ
		else
		{
			// ステータスアップできる回数を一あげる
			lotteryStatusCount++;
		}
	}

	if (canLottery == true)
	{
		// どちらかが強化できる状態だったら
		if (lotteryStatusCount != 0 || lotteryPowerCount != 0)
		{
			// 強化できるのがステータスだったらステータス強化を実行
			lotteryStatusCount > 0 ? LotteryStatus() : LotteryPower();

			// プレイヤーが選択を行い適応させるまで抽選を制限
			canLottery = false;
		}
	}
}

// ステータスアップできるものを抽選する
void BaseCharacter::LotteryStatus()
{
	// MAXをのぞいた可変長配列の初期化
	for (int i = 0; 0 < (int)BulletType::MAX - 1; i++)
	{
		// 可変長配列に要素を追加
		choiceStatus.push_back(i);
	}

	// BulletType::NORMALを削除 （begin() で戦闘を削除）
	choiceStatus.erase(choiceStatus.begin());

	// 現在の配列の大きさから表示させたい分を引いて、取り除きたい分for文を回す
	for (int i = 0; i < choiceStatus.size() - CHOICE_POWER_MAX; i++)
	{
		auto it = std::find(choiceStatus.begin(), choiceStatus.end(), GetRand(choiceStatus.size()));

		// 配列の要素数を使って乱数を取得してそのまま配列の要素を削除
		choiceStatus.erase(it);
	}

	// 選択肢を選べる状態にする
	canChoose = true;
}

// パワーアップできるものを抽選する
void BaseCharacter::LotteryPower()
{
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
		// auto型で取得してから削除
		auto it = std::find(choicePower.begin(), choicePower.end(), GetRand(choicePower.size()));

		// 配列の要素数を使って乱数を取得してそのまま配列の要素を削除
		choicePower.erase(it);
	}

	// 選択肢を選べる状態にする
	canChoose = true;
}

void BaseCharacter::ChooseBonus()
{
	// ボーナスを得ることができる状態だったら
	if (canChoose)
	{

		// 抽選できる状態に戻す
		canLottery = true;
	}
}

// 回避ボタンが押されたら移動方法をMoveからDodgeMoveに切り替える
void BaseCharacter::Dodge() { if (canDodge == true)dodgeNow = true; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

void BaseCharacter::GainExp(int expValue) { exp += expValue; }

int BaseCharacter::GetExpValue() { return exp; }
