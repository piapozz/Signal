#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter(BulletManager* bulletManager)
{
	canDodge = true;
	canLottery = true;
	playerBomb = false;
	request = 1;
	status.m_shapeSize = BOX_SIZE / 4.0f;
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
		// 移動ベクトルの長さを計算
		vecLength = sqrt(pow(dodgeVec.x, 2.0f) + pow(dodgeVec.y, 2.0f));

		// 正規化された移動ベクトルにスピードをかけて次の位置を計算
		status.m_nextPosition.x = status.m_position.x + (dodgeVec.x / vecLength) * dodgeSpeed;
		status.m_nextPosition.y = status.m_position.y + (dodgeVec.y / vecLength) * dodgeSpeed;

		// 回避時間
		if (GetNowCount() >= dodgeMoveCount + DODGE_MOVETIME)
		{
			// 回避状態を解除
			dodgeNow = false;
			// 無敵を解除
			isInvincible = false;
		}
	}

	// 通常移動
	else
	{
		if (moveVec.x != 0.0f || moveVec.y != 0.0f)
		{
			// 移動ベクトルの長さを計算
			vecLength = sqrt(pow(moveVec.x, 2.0f) + pow(moveVec.y, 2.0f));

			// 正規化された移動ベクトルにスピードをかけて次の位置を計算
			status.m_nextPosition.x = status.m_position.x + (moveVec.x / vecLength) * speed;
			status.m_nextPosition.y = status.m_position.y + (moveVec.y / vecLength) * speed;

			// printfDx("nextPosition %f", status.m_nextPosition.x);
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
	printfDx("%d\n", choiceStatus.size());
	//printfDx("LevelUpCount%d\n", levelUpCount);
	//printfDx("lotteryPowerCount%d\n", lotteryPowerCount);
	//printfDx("lotteryStatusCount%d\n", lotteryStatusCount);
	//printfDx("choicePowerArraySize%d\n", choicePower.size());
	//printfDx("choiceStatusArraySize%d\n", choiceStatus.size());
	//printfDx("Flag%d\n", GetChooceFlag());

	// レベルアップに必要な個数を満たしていたら
	if (GetExpValue() >= request)
	{
		AudioManager::GetInstance().PlaySE(SEName::LEVELUP);

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
	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		// 上限に達してる種類を配列に含めない
		if (LEVEL_MAX > bulletManager->GetBulletList()[deviceNum].m_BulletType[i])
		{
			// 可変長配列に要素を追加
			choicePower.push_back(i);
		}
	}

	// BulletType::NORMALを削除 （begin() で先頭を削除）
	choicePower.erase(choicePower.begin());

	// 現在の配列の大きさから表示させたい分を引いて、取り除きたい分for文を回す
	for (int i = 0; i < choicePower.size() - CHOICE_POWER_MAX; i++)
	{
		// auto型で取得してから削除
		// auto it = std::find(choicePower.begin(), choicePower.end(), GetRand(choicePower.size() - 1));

		// 配列の要素数を使って乱数を取得してそのまま配列の要素を削除
		choicePower.erase(choicePower.begin() + GetRand(choicePower.size() - 1));
	}

	// 抽選する回数を一回減らす
	lotteryPowerCount--;

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
	for (int i = 0; i < (int)BulletStatus::MAX; i++)
	{
		// 上限に達してる種類を配列に含めない
		if (LEVEL_MAX > bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i])
		{
			// 可変長配列に要素を追加
			choiceStatus.push_back(i);
		}
	}

	//// 現在の配列の大きさから表示させたい分を引いて、取り除きたい分for文を回す
	//for (int i = 0; i < choiceStatus.size() - CHOICE_POWER_MAX; i++)
	//{
	//	auto it = std::find(choiceStatus.begin(), choiceStatus.end(), GetRand(choiceStatus.size()));

	//	// 配列の要素数を使って乱数を取得してそのまま配列の要素を削除
	//	choiceStatus.erase(it);
	//}

	// 抽選する回数を一回減らす
	lotteryStatusCount--;

	// 選択肢を選べる状態にする
	chooseStatus = true;
}

void BaseCharacter::ChooseBonus(int selectedButton)
{
	// 強化を得ることができる状態だったら
	if (choosePower != false || chooseStatus != false)
	{
		// 上限に達していたらスキップ
		if (choiceStatus.size() == 0)
		{
			canLottery = true;
			chooseStatus = false;
		}
		// 上限に達していたらスキップ
		if (choicePower.size() == 0)
		{
			canLottery = true;
			choosePower = false;
		}

		if (selectedButton != (int)Cardinal::MAX)
		{
			// パワーアップ処理を行う
			if (choosePower)
			{
				// 中身がなかったら選択を無効にする
				if (choicePower.size() > selectedButton)
				{
					// パワーアップ
					bulletManager->LevelUpType((BulletType)choicePower[selectedButton], deviceNum);
					// 抽選できる状態に戻す
					canLottery = true;

					AudioManager::GetInstance().PlaySE(SEName::LEVELUP_DECIDE);

					choosePower = false;
				}
			}

			// ステータスアップ処理を行う 
			else if(chooseStatus)
			{
				// 中身がなかったら選択を無効にする
				if (choiceStatus.size() > selectedButton)
				{
					// ステータスアップ
					bulletManager->LevelUpStatus((BulletStatus)choiceStatus[selectedButton], deviceNum);
					// 抽選できる状態に戻す
					canLottery = true;

					AudioManager::GetInstance().PlaySE(SEName::LEVELUP_DECIDE);

					chooseStatus = false;
				}
			}
		}
	}

	else { return; }
}

// 回避ボタンが押されたら移動方法をMoveからDodgeMoveに切り替える
void BaseCharacter::Dodge()
{
	// 回避が押されたならクールタイムが上がっているかを確認
	if (canDodge == true)
	{
		// 回避状態ではなかったら回避を開始
		if (dodgeNow != true)
		{
			// 移動方向を保存
			dodgeVec = moveVec;

			// 移動方向がなかったら回避しない
			if (dodgeVec.x != 0 || dodgeVec.y != 0)
			{
				// 計測を開始
				dodgeMoveCount = GetNowCount();

				// クールタイムを発生させる
				dodgeCooltime = GetNowCount();

				// 効果音を鳴らす
				AudioManager::GetInstance().PlaySE(SEName::DODGE);

				// 回避中に状態を変更
				dodgeNow = true;

				// 無敵にする
				isInvincible = true;

				// 回避不可能状態にする
				canDodge = false;
			}
		}
	}
}

void BaseCharacter::DodgeCoolTime()
{
	// 回避ができなくなったらクールタイムを開始
	if (canDodge == false)
	{
		// 
		if (GetNowCount() >= dodgeCooltime + DODGE_COOLTIME)
		{
			canDodge = true;
		}
	}

}

//// 配列の中身を削除
//std::vector<int>DeleteVector(std::vector<int> vector)
//{
//	// 配列の大きさ分繰り返して中身を削除する
//	for (int i = 0; i < vector.size(); i++)
//	{
//		vector.erase(vector.begin());
//	}
//
//	return vector;
//}

// プレイヤーに番号を振り分け
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// 引数でもらった番号をプレイヤー番号に設定
	playerNum = playerNumber;
}

void BaseCharacter::SetSurvival() 
{
	// 体力が0になったときプレイヤーは死にます
	if (status.m_life <= 0 && playerBomb != true)
	{
		// 時間を保存
		playerBombCount = GetNowCount();

		// 爆発を実行
		BaseChamber::ExplosionContainer temp;
		temp.expansionRange = 5;
		temp.time = PLAYER_BOMB_TIME / 1000;

		bulletManager->CreateExplosion(status, temp);

		// プレイヤー爆発フラグを動かす
		playerBomb = true;
	}

	// 爆発が終わった時、プレイヤーを死亡させる
	if (playerBomb == true && GetNowCount() >= playerBombCount + PLAYER_BOMB_TIME)status.m_isActive = false;
}

Vector2 BaseCharacter::GetPlayerPos() { return status.m_position; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

bool BaseCharacter::GetIsInvincible() { return isInvincible; }

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
int BaseCharacter::GetRequestValue() { return request; }
