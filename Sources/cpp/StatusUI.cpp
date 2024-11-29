#include "../header/StatusUI.h"

// 色々なものを初期化する
StatusUI::StatusUI(BulletManager* bulletManager, Vector2 position)
{
	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("Resources/Bullet_Normal.png");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("Resources/Bullet_Explosion.png");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("Resources/Bullet_MultiShot.png");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("Resources/Bullet_Penetration.png");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("Resources/Bullet_Reflection.png");
	bulletIcon[(int)BulletType::TRACKING_SHOT] = LoadGraph("");

	bulletStateText[(int)BulletStatus::SPEED] = "SPEED";
	bulletStateText[(int)BulletStatus::POWER] = "POWER";
	bulletStateText[(int)BulletStatus::RANGE] = "RANGE";
	bulletStateText[(int)BulletStatus::RATE] = "RATE";

	levelViewIcon = LoadGraph("Resources/Bullet_Level_Bar.png");

	// 初期位置を更新
	initPos = position;

	// bulletManagerを継ぎながら取得
	bullet = bulletManager;
}

StatusUI::~StatusUI()
{

}

// アイコンとその弾のレベルを描画
void StatusUI::ArrangeIcon(int deviceNum)
{
	// 描画する座標の左上の頂点座標を初期化
	Vector2 infoPos = initPos;
	Vector2 barPos;

	infoPos.x -= BULLET_ICON_HEIGHT;

	// 弾の種類を描画
	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		infoPos.x += BULLET_ICON_HEIGHT;
		// infoPos.y += BULLET_ICON_WIDTH * ;

		// 描画
		DrawExtendGraph(infoPos.x, infoPos.y, infoPos.x + BULLET_ICON_HEIGHT, infoPos.y + BULLET_ICON_WIDTH, bulletIcon[i], TRUE);

		// 弾のレベルバーを描画
		for (int j = 0; j < LEVEL_MAX; j++)
		{
			// 間隔を調節するための変数
			Vector2 distanceError;

			// 定数を使ってx,yそれぞれの誤差を初期化する
			//distanceError.x = j * LEVEL_BAR_HEIGHT;
			//distanceError.y = j * LEVEL_BAR_WIDTH;

			barPos = infoPos;

			// 高さを調節
			barPos.y += BULLET_ICON_WIDTH + LEVEL_BAR_WIDTH;

			// 弾のレベルを見てレベル分レベルバーを描画する
			if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i])
			{
				barPos.y += LEVEL_BAR_WIDTH;
				// レベルバーを描画
				DrawExtendGraph(barPos.x, barPos.y , barPos.x + BULLET_ICON_HEIGHT, barPos.y + LEVEL_BAR_WIDTH, levelViewIcon, TRUE);
			}
		}
	}
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
		for (int j = 0; j < 10; j++)
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
	Vector2 centerPos;

	// 配列の分プレイヤーの周りにUIを描画
	for (int i = 0; i < vectorArray.size(); i++)
	{
		// 「i」の状態を見て方角を分岐 ※北東南西の順番で描画
		switch (i)
		{
		case (int)Cardinal::WEST:
			centerPos.x = -DISTANCE_ERROR;
			centerPos.y = 0.0f;

			break;
		case (int)Cardinal::NORTH:
			centerPos.x = 0.0f;
			centerPos.y = -DISTANCE_ERROR;

			break;
		case (int)Cardinal::EAST:
			centerPos.x = DISTANCE_ERROR;
			centerPos.y = 0.0f;

			break;
		case (int)Cardinal::SOUTH:
			centerPos.x = 0.0f;
			centerPos.y = DISTANCE_ERROR;

			break;
		}

		// プレイヤーから方角に合わせる
		centerPos = centerPos + playerPos;

		// 画像を描画
		// DrawRotaGraph(tempPos.x, tempPos.y, 1.0f, DX_PI_F / 2, bulletIcon[vectorArray[i]], TRUE);

		DrawExtendGraph(centerPos.x - TYPE_ICON.x, centerPos.y - TYPE_ICON.y, centerPos.x + TYPE_ICON.x, centerPos.y + TYPE_ICON.y, bulletIcon[vectorArray[i]], TRUE);
	}
}