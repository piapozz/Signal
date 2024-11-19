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

		infoPos.x += 100;


		DrawFormatString(infoPos.x + i, infoPos.y, COLOR_BLACK, bulletStateText[i].c_str());


		// ステータスの値によって星を描画
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			infoPos.y += 50;
			if (i < bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "★"); }
			else DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "☆");
		}
	}
}

void UIManager::LevelUpUI()
{

}

// 弾のステータスを描画
void UIManager::StatusViewer(int deviceNum)
{
	// ステータスの状態を星で描画
	for (int i = 0; i < 5; i++)
	{

		infoPos.x += 100;

		// ステータス名
		DrawFormatString(infoPos.x + i, infoPos.y, COLOR_BLACK, bulletStateText[i].c_str());


		// ステータスの値によって星を描画
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			infoPos.y += 50;
			// ステータスのレベルが「i」を超えていたら黒星で描画
			if (i < bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "★"); }
			// 超えていなかったら白星で描画
			else DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "☆");
		}
	}
}

// プレイヤーの周りにステータスを描画
void UIManager::PlayerAround(std::vector<int> vectorArray, Vector2 playerPos)
{
	Vector2 tempPos;

	// 配列の分プレイヤーの周りにUIを描画
	for (int i = 0; i < vectorArray.size(); i++)
	{
		// 「i」の状態を見て方角を分岐 ※北東南西の順番で描画
		switch (i)
		{
		case (int)Cardinal::NORTH:
			tempPos.x = 0.0f;
			tempPos.y = -distanceError;

			break;
		case (int)Cardinal::EAST:
			tempPos.x = distanceError;
			tempPos.y = 0.0f;

			break;
		case (int)Cardinal::SOUTH:
			tempPos.x = 0.0f;
			tempPos.y = distanceError;

			break;
		case (int)Cardinal::WEST:
			tempPos.x = -distanceError;
			tempPos.y = 0.0f;

			break;
		}

		// プレイヤーから方角に合わせる
		tempPos = tempPos + playerPos;

		// 画像を描画
		DrawRotaGraph(tempPos.x, tempPos.y, 1.0f, DX_PI_F / 2, statusImage[vectorArray[i]], TRUE);
	}
}