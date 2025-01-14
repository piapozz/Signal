#include "../header/UIManager.h"

UIManager::UIManager()
{
	initPos[0] = { 0.0f,25.0f };
	initPos[1] = { 1500.0f,25.0f };
	// initPos[2] = { 1500.0f,25.0f };
	// initPos[2] = { 0.0f,750.0f };
	// initPos[3] = { 1500,750.0f };

	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("Resources/Bullet_Normal.png");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("Resources/Bullet_Explosion.png");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("Resources/Bullet_MultiShot.png");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("Resources/Bullet_Penetration.png");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("Resources/Bullet_Reflection.png");

	statusIcon[(int)BulletStatus::SPEED] = LoadGraph("Resources/Status_Speed.png");
	statusIcon[(int)BulletStatus::POWER] = LoadGraph("Resources/Status_Power.png");
	statusIcon[(int)BulletStatus::RANGE] = LoadGraph("Resources/Status_Range.png");
	statusIcon[(int)BulletStatus::RATE] = LoadGraph("Resources/Status_Rate.png");
}

UIManager::~UIManager()
{

}

void UIManager::Init(BulletManager* bulletManager, std::vector<BaseCharacter*> devicesObject)
{
	bullet = bulletManager;

	// デバイスの状態を保持
	devices = devicesObject;

	// UI本体を生成
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		statusUI.push_back(new StatusUI(bullet, initPos[i]));
	}
}

void UIManager::Proc()
{

}

void UIManager::Draw()
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		// 取得している射撃タイプを画像で順番に並べる
		statusUI[i]->ArrangeIcon(devices[i]->deviceNum,bulletIcon);

		// ステータスの状態を星で描画
		statusUI[i]->StatusViewer(devices[i]->deviceNum);

		// レベルアップしたとき強化する物を表示

		// フラグの状態を取得
		flagStatus = devices[i]->GetChooceFlag();

		if (flagStatus == 1)
		{
			statusUI[i]->PlayerAround(devices[i]->choicePower, devices[i]->GetDisplayPos(), bulletIcon);
		}
		else if (flagStatus == 2)
		{
			statusUI[i]->PlayerAround(devices[i]->choiceStatus, devices[i]->GetDisplayPos(), statusIcon);
		}

		// レベルの表示
		statusUI[i]->PlayerLevel(devices[i]->levelUpCount);

		// 経験値/必要量 の表示
		statusUI[i]->RequestCount(devices[i]->GetExpValue(), devices[i]->GetRequestValue());
	}

	TutorialDraw();
}

void UIManager::TutorialDraw()
{
	DrawFormatString(1700, 980, COLOR_WHITE, "左スティック：移動");
	DrawFormatString(1700, 1000, COLOR_WHITE, "右スティック：回転");
	DrawFormatString(1700, 1020, COLOR_WHITE, "左トリガー：回避");
	DrawFormatString(1700, 1040, COLOR_WHITE, "右トリガー：射撃");
	DrawFormatString(1700, 1060, COLOR_WHITE, "右ボタン：スキル選択");
}