#include "../header/UIManager.h"

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

void UIManager::Proc()
{

}

void UIManager::Draw(int deviceNum, BulletManager* bullet)
{
	if (deviceNum == 1)
	{
		infoHeight = PLAYER_HEIGHT_1;
		infoWidth = PLAYER_WIDTH_1;
	}

	else if (deviceNum == 2)
	{
		infoHeight = PLAYER_HEIGHT_2;
		infoWidth = PLAYER_WIDTH_2;
	}

	else { return; }

	/*
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "射撃タイプ画像");

	DrawFormatString(infoHeight + 30, infoWidth, COLOR_BLACK, "Speed : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::SPEED]);

	DrawFormatString(infoHeight + 60, infoWidth, COLOR_BLACK, "Power : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::POWER]);

	DrawFormatString(infoHeight + 90, infoWidth, COLOR_BLACK, "Range : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::RANGE]);

	DrawFormatString(infoHeight + 120, infoWidth, COLOR_BLACK, "Rate : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::RATE]);]
	*/

	printfDx("射撃タイプ画像\n");
	printfDx("Speed : %f\n", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::SPEED]);
	printfDx("Power : %f\n", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::POWER]);
	printfDx("Range : %f\n", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::RANGE]);
	printfDx("Rate : %f\n", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::RATE]);

	// FPSの描画
	DrawBox(1810, 0, 1920, 20, GetColor(30, 30, 30), true);
	DrawFormatString(1820, 0, GetColor(0, 255, 125), "FPS : %.1f", GetFPS());
}

void UIManager::StatusList(int statusType)
{
	switch (statusType)
	{





	}
}