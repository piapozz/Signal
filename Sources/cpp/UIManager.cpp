#include "../header/UIManager.h"

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

void UIManager::Proc()
{
	// �v���C���[�����擾
	// deviceCount = inputManager->GetPlayerNum();

	// �f�o�C�X�̕�����UI��\��
	for (int i = 1; deviceMax < 1; i++)
	{

	}

}

void UIManager::Draw(int playerNum)
{
	DrawFormatString(15, 5, COLOR_BLACK, "Speed : %f", bulletManager->_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::SPEED]);
	DrawFormatString(15, 35, COLOR_BLACK, "Power : %f", bulletManager->_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::POWER]);
	DrawFormatString(15, 65, COLOR_BLACK, "Range : %f", bulletManager->_bulletPram[playerNum].m_BulletStatus[(int)BulletStatus::RANGE]);
}

void UIManager::StatusList(int statusType)
{
	switch (statusType)
	{





	}
}