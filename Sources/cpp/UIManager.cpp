#include "../header/UIManager.h"

UIManager::UIManager()
{
	bulletManager = new BulletManager();
}

UIManager::~UIManager()
{
	delete bulletManager;
}

void UIManager::Proc()
{
	// デバイスの分だけUIを表示
	for (int i = 1; deviceMax < 1; i++)
	{
		Draw(i);
	}

}

void UIManager::Draw(int deviceNum)
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

	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "射撃タイプ画像");

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Speed : %f", bulletManager->_bulletPram[deviceNum].m_BulletStatus[(int)BulletStatus::SPEED]);

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Power : %f", bulletManager->_bulletPram[deviceNum].m_BulletStatus[(int)BulletStatus::POWER]);

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Range : %f", bulletManager->_bulletPram[deviceNum].m_BulletStatus[(int)BulletStatus::RANGE]);

	infoHeight += 30;
	DrawFormatString(infoHeight, infoWidth, COLOR_BLACK, "Rate : %f", bulletManager->_bulletPram[deviceNum].m_BulletStatus[(int)BulletStatus::RATE]);
}

void UIManager::StatusList(int statusType)
{
	switch (statusType)
	{





	}
}