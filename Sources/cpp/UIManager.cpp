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
			/*
			if (j < bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x + i * 30, infoPos.y, COLOR_BLACK, "★"); }
			else DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "☆");
			*/

			// 星マーク格納用変数
			string starMark;

			// ステータスの状態でどっちが入るかを決める
			starMark = j < bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i] ? "★" : "☆";

			// 決めた評価を使って描画
			DrawFormatString(infoPos.x + i * 30, infoPos.y, COLOR_BLACK, starMark.c_str());
		}
	}
}

void UIManager::LevelUpUI()
{

}