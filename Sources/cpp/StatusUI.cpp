#include "../header/StatusUI.h"

// 色々なものを初期化する
StatusUI::StatusUI(BulletManager* bulletManager, Vector2 position)
{
	bulletStateText[(int)BulletStatus::SPEED] = "SPEED";
	bulletStateText[(int)BulletStatus::POWER] = "POWER";
	bulletStateText[(int)BulletStatus::RANGE] = "RANGE";
	bulletStateText[(int)BulletStatus::RATE] = "RATE";

	levelViewIcon = LoadGraph("Resources/Bullet_Level_Bar.png");

	statusDiaIcon[(int)UIGraph::STATUS_DIA_BASE] = LoadGraph(UI_GRAPH_ADRESS[(int)UIGraph::STATUS_DIA_BASE].c_str());
	statusDiaIcon[(int)UIGraph::STATUS_DIA] = LoadGraph(UI_GRAPH_ADRESS[(int)UIGraph::STATUS_DIA].c_str());

	// 初期位置を更新
	initPos = position;

	// bulletManagerを継ぎながら取得
	bullet = bulletManager;

	SetFontSize(20);
}

StatusUI::~StatusUI()
{

}

// アイコンとその弾のレベルを描画
void StatusUI::ArrangeIcon(int deviceNum, int imageHandle[])
{
	// 描画する座標の左上の頂点座標を初期化
	Vector2 infoPos = initPos;
	Vector2 barPos;

	infoPos.x -= BULLET_ICON_HEIGHT;

	// 弾の種類を描画
	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		// ノーマルの描画を飛ばす
		if (i == (int)BulletType::NORMAL) continue;

		infoPos.x += BULLET_ICON_HEIGHT;
		// infoPos.y += BULLET_ICON_WIDTH * ;

		// 描画
		DrawExtendGraph(infoPos.x, infoPos.y, infoPos.x + BULLET_ICON_HEIGHT, infoPos.y + BULLET_ICON_WIDTH, imageHandle[i], TRUE);

		// 弾のレベルバーを描画
		for (int j = 0; j < bullet->GetBulletList()[deviceNum].m_BulletType[i]; j++)
		{
			barPos = infoPos;

			// 高さを調節
			barPos.y += BULLET_ICON_WIDTH;

			// 弾のレベルを見てレベル分レベルバーを描画する
			if (j < bullet->GetBulletList()[deviceNum].m_BulletType[i])
			{
				barPos.y += BAR_TO_BAR_ERROR * j;
				// レベルバーを描画
				DrawExtendGraph(barPos.x, barPos.y, barPos.x + BULLET_ICON_HEIGHT, barPos.y + LEVEL_BAR_WIDTH, levelViewIcon, TRUE);
			}
		}
	}
}

// 弾のステータスを描画
void StatusUI::StatusViewer(int deviceNum)
{
	Vector2 infoPos;

	// 高さの初期位置
	infoPos.y = initPos.y + 150.0f;

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
			//// ステータスのレベルが「i」を超えていたら黒星で描画
			//if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "★"); }
			//// 超えていなかったら白星で描画
			//else DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "☆");

			// ステータスのレベルが「i」を超えていたら星で描画
			if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawExtendGraph(infoPos.x, infoPos.y, infoPos.x + 20, infoPos.y + 20, statusDiaIcon[(int)UIGraph::STATUS_DIA], TRUE); }
			// 超えていなかったら中身のない星で描画
			else DrawExtendGraph(infoPos.x, infoPos.y, infoPos.x + 20, infoPos.y + 20, statusDiaIcon[(int)UIGraph::STATUS_DIA_BASE], TRUE);

		}
	}
}

// プレイヤーの周りにステータスを描画
void StatusUI::PlayerAround(std::vector<int> vectorArray, Vector2 playerPos,int imageHandle[])
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

		DrawExtendGraph(centerPos.x - TYPE_ICON.x, centerPos.y - TYPE_ICON.y, centerPos.x + TYPE_ICON.x, centerPos.y + TYPE_ICON.y, imageHandle[vectorArray[i]], TRUE);
	}
}

void StatusUI::RequestCount(int exp, int request)
{
	// 初期化
	Vector2 infoPos = initPos;

	// 高さの初期位置
	infoPos.y = initPos.y + 150.0f;

	DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "NextLevel: %d / %d", exp, request);
}

void StatusUI::PlayerLevel(int playerLevel)
{
	// 初期化
	Vector2 infoPos = initPos;

	// 高さの初期位置
	infoPos.y = initPos.y + 130.0f;

	DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "PlayerLevel:%d", playerLevel);
}