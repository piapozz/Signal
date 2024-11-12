#include "../header/UIManager.h"

UIManager::UIManager()
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
}

UIManager::~UIManager()
{

}

void UIManager::Init()
{

}

void UIManager::Proc()
{

}

void UIManager::Draw(int deviceNum, BulletManager* bullet)
{
	// �f�o�C�X�ԍ��ɉ����ăZ�b�e�B���O����
	switch (deviceNum)
	{
	case 1:
		infoHeight = PLAYER_HEIGHT_1;
		infoWidth = PLAYER_WIDTH_1;

		break;
	case 2:


		break;
	case 3:


		break;
	case 4:


		break;

	}


	// �擾���Ă���ˌ��^�C�v���摜�ŏ��Ԃɕ��ׂ�




	// �擾���Ă���ˌ��^�C�v�̉��Ƀ��x����\������

	// �ˌ��̃X�e�[�^�X�𐯂ŕ`�悷��
	// �X�e�[�^�X���O���珇�ԂɌ���
	//for (int i = 0; i < (int)BulletStatus::MAX; i++)
	//{
	//	DrawFormatString(infoHeight + i * 50, infoWidth, COLOR_BLACK, "Speed %f");

	//	// �X�e�[�^�X�̒l�ɂ���Đ���`��
	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (i < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoHeight + i * 50, infoWidth + j * 30, COLOR_BLACK, "��"); }
	//		else DrawFormatString(infoHeight + i * 50, infoWidth + j * 30, COLOR_BLACK, "��");
	//	}
	//}

	for (int i = 0; i < 5; i++)
	{
		infoHeight += 100;


		DrawFormatString(infoHeight + i, infoWidth, COLOR_BLACK, bulletStateText[i].c_str());

		// �X�e�[�^�X�̒l�ɂ���Đ���`��
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			if (i < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoHeight + i * 30, infoWidth + j * 20, COLOR_BLACK, "��"); }
			else DrawFormatString(infoHeight + i * 30, infoWidth + j * 20, COLOR_BLACK, "��");
		}
	}
}

void UIManager::LevelUpUI()
{



}