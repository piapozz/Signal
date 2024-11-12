#include "../header/UIManager.h"

UIManager::UIManager()
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
}

UIManager::~UIManager()
{

}

void UIManager::Init()
{

}

void UIManager::Proc()
{

}

void UIManager::Draw(int deviceNum, BulletManager* bullet)
{
	// デバイス番号に応じてセッティングする
	switch (deviceNum)
	{
	case 1:
		infoHeight = PLAYER_HEIGHT_1;
		infoWidth = PLAYER_WIDTH_1;

		break;
	case 2:


		break;
	case 3:


		break;
	case 4:


		break;

	}


	// 取得している射撃タイプを画像で順番に並べる




	// 取得している射撃タイプの下にレベルを表示する

	// 射撃のステータスを星で描画する
	// ステータスを０から順番に見る
	//for (int i = 0; i < (int)BulletStatus::MAX; i++)
	//{
	//	DrawFormatString(infoHeight + i * 50, infoWidth, COLOR_BLACK, "Speed %f");

	//	// ステータスの値によって星を描画
	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (i < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoHeight + i * 50, infoWidth + j * 30, COLOR_BLACK, "★"); }
	//		else DrawFormatString(infoHeight + i * 50, infoWidth + j * 30, COLOR_BLACK, "☆");
	//	}
	//}

	for (int i = 0; i < 5; i++)
	{
		infoHeight += 100;


		DrawFormatString(infoHeight + i, infoWidth, COLOR_BLACK, bulletStateText[i].c_str());

		// ステータスの値によって星を描画
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			if (i < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoHeight + i * 30, infoWidth + j * 20, COLOR_BLACK, "★"); }
			else DrawFormatString(infoHeight + i * 30, infoWidth + j * 20, COLOR_BLACK, "☆");
		}
	}
}

void UIManager::LevelUpUI()
{



}