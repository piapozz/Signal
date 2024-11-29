#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter(BulletManager* bulletManager)
{
	canLottery = true;
	request = 3;
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

// 経験値を見て
void BaseCharacter::ObserveExp()
{
	printfDx("%d\n", GetExpValue());
	printfDx("LevelUpCount%d\n", levelUpCount);
	printfDx("lotteryPowerCount%d\n", lotteryPowerCount);
	printfDx("lotteryStatusCount%d\n", lotteryStatusCount);
	printfDx("choicePowerArraySize%d\n", choicePower.size());
	printfDx("choiceStatusArraySize%d\n", choiceStatus.size());
	printfDx("Flag%d\n", GetChooceFlag());

	// レベルアップに必要な個数を満たしていたら
	if (GetExpValue() >= request)
	{
		// 経験値をリセット
		exp -= request;

		// レベルアップしたら次のレベルアップに必要なコストを上げる
		request = request + 1;

		levelUpCount++;

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

	// 抽選ができる状態だったら
	if (canLottery == true)
	{
		// どちらかの値が「0」ではなかったら選択肢の抽選を行う
		if (lotteryStatusCount != 0 || lotteryPowerCount != 0)
		{
			// パワーアップを優先で強化できるものの抽選を行う
			lotteryPowerCount > 0 ? LotteryPower() : LotteryStatus();

			// プレイヤーが選択を行い適応させるまで抽選を制限
			canLottery = false;
		}
	}
}

// パワーアップできるものを抽選する
void BaseCharacter::LotteryPower()
{
	// 初期化
	// choicePower = DeleteVector(choicePower);
	choicePower.clear();

	// 列挙体MAXをのぞいた可変長配列の初期化
	for (int i = 0; i < (int)BulletType::MAX - 1; i++)
	{
		// 可変長配列に要素を追加
		choicePower.push_back(i);
	}

	// BulletType::NORMALを削除 （begin() で先頭を削除）
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
	choosePower = true;
}

// ステータスアップできるものを抽選する
void BaseCharacter::LotteryStatus()
{
	// 初期化
	// choiceStatus = DeleteVector(choiceStatus);
	choiceStatus.clear();

	// MAXをのぞいた可変長配列の初期化
	for (int i = 0; i < (int)BulletStatus::MAX - 1; i++)
	{
		// 可変長配列に要素を追加
		choiceStatus.push_back(i);
	}

	// 現在の配列の大きさから表示させたい分を引いて、取り除きたい分for文を回す
	for (int i = 0; i < choiceStatus.size() - CHOICE_POWER_MAX; i++)
	{
		auto it = std::find(choiceStatus.begin(), choiceStatus.end(), GetRand(choiceStatus.size()));

		// 配列の要素数を使って乱数を取得してそのまま配列の要素を削除
		choiceStatus.erase(it);
	}

	// 選択肢を選べる状態にする
	chooseStatus = true;
}

void BaseCharacter::ChooseBonus(int selectedButton)
{
	// 強化を得ることができる状態だったら
	if (choosePower != false || chooseStatus != false)
	{

		if (selectedButton != (int)Cardinal::MAX)
		{
			// パワーアップ処理を行う
			if (choosePower)
			{
				// パワーアップ
				bulletManager->LevelUpType((BulletType)choicePower[selectedButton], deviceNum);
				lotteryPowerCount--;
				choosePower = false;
			}

			// ステータスアップ処理を行う 
			else
			{
				// ステータスアップ
				bulletManager->LevelUpStatus((BulletStatus)choiceStatus[selectedButton], deviceNum);
				lotteryStatusCount--;
				chooseStatus = false;
			}

			// 抽選できる状態に戻す
			canLottery = true;
		}
	}

	else { return; }
}

// 回避ボタンが押されたら移動方法をMoveからDodgeMoveに切り替える
void BaseCharacter::Dodge() { if (canDodge == true)dodgeNow = true; }

// 配列の中身を削除
std::vector<int>DeleteVector(std::vector<int> vector)
{
	// 配列の大きさ分繰り返して中身を削除する
	for (int i = 0; i < vector.size(); i++)
	{
		vector.erase(vector.begin());
	}

	return vector;
}

// プレイヤーに番号を振り分け
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// 引数でもらった番号をプレイヤー番号に設定
	playerNum = playerNumber;
}

Vector2 BaseCharacter::GetPlayerPos() { return status.m_position; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

/// <summary>
/// フラグがtrueになっているかどうか確かめる
/// </summary>
/// <param name="0">trueになっているフラグはない</param>
/// <param name="1">choosePowerがtrue</param>
/// <param name="2">chooseStatusがtrue</param>
int BaseCharacter::GetChooceFlag()
{
	if (choosePower) return 1;
	if (chooseStatus) return 2;

	return 0;
}

void BaseCharacter::GainExp(int expValue) { exp += expValue; }

int BaseCharacter::GetExpValue() { return exp; }
