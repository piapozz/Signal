#include "../header/UIManager.h"

UIManager::UIManager()
{
	initPos[0] = { 0.0f,25.0f };
	initPos[1] = { 1500.0f,25.0f };
	// initPos[2] = { 0.0f,750.0f };
	// initPos[3] = { 1500,750.0f };

	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("Resources/Bullet_Normal.png");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("Resources/Bullet_Explosion.png");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("Resources/Bullet_MultiShot.png");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("Resources/Bullet_Penetration.png");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("Resources/Bullet_Reflection.png");
	bulletIcon[(int)BulletType::TRACKING_SHOT] = LoadGraph("");

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
		// 取得している射撃タイプの下にレベルを表示する
		// statusUI[i]->
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

	}
}