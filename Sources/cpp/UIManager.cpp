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

	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "ŽËŒ‚ƒ^ƒCƒv‰æ‘œ");

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Speed : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::SPEED]);

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Power : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::POWER]);

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Range : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::RANGE]);

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Rate : %f", bullet->GetBulletList()[deviceNum].m_BulletStatus[(int)BulletStatus::RATE]);
}

void UIManager::StatusList(int statusType)
{
	switch (statusType)
	{





	}
}