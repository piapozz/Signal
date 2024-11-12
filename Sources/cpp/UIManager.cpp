#include "../header/UIManager.h"

UIManager::UIManager(Vector2 initPos)
{
	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("");
	bulletIcon[(int)BulletType::TRACKING_SHOT] = LoadGraph("");

	bulletStateText[(int)BulletStatus::SPEED] = "SPEED";
	bulletStateText[(int)BulletStatus::POWER] = "POWER";
	bulletStateText[(int)BulletStatus::RANGE] = "RANGE";
	bulletStateText[(int)BulletStatus::RATE] = "RATE";

	infoPos = initPos;
}

UIManager::~UIManager()
{

}

void UIManager::Init(BulletManager* bullet)
{
	bulletManager = bullet;
}

void UIManager::Proc()
{

}

void UIManager::Draw(int deviceNum)
{
	// 取得している射撃タイプを画像で順番に並べる


	// 取得している射撃タイプの下にレベルを表示する


	// ステータスの状態を星で描画
	for (int i = 0; i < 5; i++)
	{
		infoPos.y += 100;


		DrawFormatString(infoPos.x, infoPos.y, COLOR_BLACK, bulletStateText[i].c_str());

		// ステータスの値によって星を描画
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x + i * 30, infoPos.y, COLOR_BLACK, "★"); }
			else DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "☆");
		}
	}
}

void UIManager::LevelUpUI()
{
	// レベルアップに必要な個数を満たしていたら
	if (players[i]->GetExpValue() >= players[i]->request)
	{

		// レベルアップしたら次のレベルアップに必要なコストを上げる
		players[i]->request += 3;

		// 三の倍数回これまでにレベルアップしていたらパワーアップから選ぶ
		if (players[i]->levelUpCount % 3)
		{
			// パワーアップできる回数を一あげる


		}

		// 三の倍数回ではなかったらステータスから選ぶ
		else
		{
			// ステータスアップできる回数を一あげる


		}

	}

	// レベルアップできる回数を見てコントローラーの入力を受け取り結果を反映させる
	// パワーアップを行う
	if (players[i]->powerUpCount)
	{
		// 列挙体BulletTypeの大きさを使って乱数を取得 
		GetRand((int)BulletType::MAX);


	}

	// ステータスアップを行う
	else if (players[i]->statusUpCount)
	{

		GetRand((int)BulletStatus::MAX);

	}

}