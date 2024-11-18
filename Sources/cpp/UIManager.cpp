#include "../header/UIManager.h"

UIManager::UIManager(Vector2 initPos)
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

	infoPos = initPos;
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
	// �擾���Ă���ˌ��^�C�v���摜�ŏ��Ԃɕ��ׂ�


	// �擾���Ă���ˌ��^�C�v�̉��Ƀ��x����\������


	// �X�e�[�^�X�̏�Ԃ𐯂ŕ`��
	for (int i = 0; i < 5; i++)
	{

		infoPos.x += 100;


		DrawFormatString(infoPos.x + i, infoPos.y, COLOR_BLACK, bulletStateText[i].c_str());


		// �X�e�[�^�X�̒l�ɂ���Đ���`��
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			infoPos.y += 50;
			if (i < bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "��"); }
			else DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "��");
		}
	}
}

void UIManager::LevelUpUI()
{

}

// ������BaseCharacter��choiceStatus�z����󂯎��`��
void UIManager::StatusUpUI(std::vector<int> statusArray)
{
	// �z��̃T�C�Y��������
	for (int i = 0; i < statusArray.size(); i++)
	{

	}
}

// ������BaseCharacter��choicePower�z����󂯎��`��
void UIManager::StatusUpUI(std::vector<int> powerArray)
{
	// �z��̃T�C�Y��������
	for (int i = 0; i < powerArray.size(); i++)
	{

	}
}