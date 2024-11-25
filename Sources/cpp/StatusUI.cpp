#include "../header/StatusUI.h"

StatusUI::StatusUI(BulletManager* bulletManager, Vector2 position)
{
	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("Resources/Bullet_2.png");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("Resources/Bullet_1.png");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("");
	bulletIcon[(int)BulletType::TRACKING_SHOT] = LoadGraph("");

	bulletStateText[(int)BulletStatus::SPEED] = "SPEED";
	bulletStateText[(int)BulletStatus::POWER] = "POWER";
	bulletStateText[(int)BulletStatus::RANGE] = "RANGE";
	bulletStateText[(int)BulletStatus::RATE] = "RATE";

	// 初期位置を更新
	initPos = position;

	bullet = bulletManager;
}

StatusUI::~StatusUI()
{

}

void StatusUI::ArrangeIcon()
{
	Vector2 infoPos;

	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		infoPos.x += BULLET_ICON_HEIGHT * i;
		infoPos.y += BULLET_ICON_WIDTH * i;

		DrawExtendGraph(initPos.x, initPos.y, initPos.x * 2, initPos.y * 2, bulletIcon[i], TRUE);
	}
}

void StatusUI::BulletLevel()
{

}

// 弾のステータスを描画
void StatusUI::StatusViewer(int deviceNum)
{
	Vector2 infoPos;

	// 高さの初期位置
	infoPos.y = initPos.y;

	int textError = 0;

	// 文字と星の間の空白の長さを文字数が一番多い値に調節
	for (int i = 0; i < (int)BulletStatus::MAX; i++) if (textError <= bulletStateText[i].size())textError = bulletStateText[i].size();

	// ステータスの状態を星で描画
	for (int i = 0; i < (int)BulletStatus::MAX; i++)
	{
		infoPos.x = initPos.x;
		infoPos.y += 20.0f;

		// ステータス名
		DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, bulletStateText[i].c_str());

		// ステータスの値によって星を描画
		for (int j = 0; j < 5; j++)
		{
			infoPos.x = initPos.x;
			// 
			infoPos.x += j * STAR_TO_STAR + textError * TEXT_TO_STAR;
			// ステータスのレベルが「i」を超えていたら黒星で描画
			if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "★"); }
			// 超えていなかったら白星で描画
			else DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "☆");
		}
	}
}

// プレイヤーの周りにステータスを描画
void StatusUI::PlayerAround(std::vector<int> vectorArray, Vector2 playerPos)
{
	Vector2 tempPos;

	// 配列の分プレイヤーの周りにUIを描画
	for (int i = 0; i < vectorArray.size(); i++)
	{
		// 「i」の状態を見て方角を分岐 ※北東南西の順番で描画
		switch (i)
		{
		case (int)Cardinal::WEST:
			tempPos.x = -DISTANCE_ERROR;
			tempPos.y = 0.0f;

			break;
		case (int)Cardinal::NORTH:
			tempPos.x = 0.0f;
			tempPos.y = -DISTANCE_ERROR;

			break;
		case (int)Cardinal::EAST:
			tempPos.x = DISTANCE_ERROR;
			tempPos.y = 0.0f;

			break;
		case (int)Cardinal::SOUTH:
			tempPos.x = 0.0f;
			tempPos.y = DISTANCE_ERROR;

			break;
		}

		// プレイヤーから方角に合わせる
		tempPos = tempPos + playerPos;

		// 画像を描画
		DrawRotaGraph(tempPos.x, tempPos.y, 1.0f, DX_PI_F / 2, bulletIcon[vectorArray[i]], TRUE);
	}
}