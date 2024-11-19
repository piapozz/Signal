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

// �e�̃X�e�[�^�X��`��
void UIManager::StatusViewer(int deviceNum)
{
	// �X�e�[�^�X�̏�Ԃ𐯂ŕ`��
	for (int i = 0; i < 5; i++)
	{

		infoPos.x += 100;

		// �X�e�[�^�X��
		DrawFormatString(infoPos.x + i, infoPos.y, COLOR_BLACK, bulletStateText[i].c_str());


		// �X�e�[�^�X�̒l�ɂ���Đ���`��
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			infoPos.y += 50;
			// �X�e�[�^�X�̃��x�����ui�v�𒴂��Ă����獕���ŕ`��
			if (i < bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "��"); }
			// �����Ă��Ȃ������甒���ŕ`��
			else DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "��");
		}
	}
}

// �v���C���[�̎���ɃX�e�[�^�X��`��
void UIManager::PlayerAround(std::vector<int> vectorArray, Vector2 playerPos)
{
	Vector2 tempPos;

	// �z��̕��v���C���[�̎����UI��`��
	for (int i = 0; i < vectorArray.size(); i++)
	{
		// �ui�v�̏�Ԃ����ĕ��p�𕪊� ���k���쐼�̏��Ԃŕ`��
		switch (i)
		{
		case (int)Cardinal::NORTH:
			tempPos.x = 0.0f;
			tempPos.y = -distanceError;

			break;
		case (int)Cardinal::EAST:
			tempPos.x = distanceError;
			tempPos.y = 0.0f;

			break;
		case (int)Cardinal::SOUTH:
			tempPos.x = 0.0f;
			tempPos.y = distanceError;

			break;
		case (int)Cardinal::WEST:
			tempPos.x = -distanceError;
			tempPos.y = 0.0f;

			break;
		}

		// �v���C���[������p�ɍ��킹��
		tempPos = tempPos + playerPos;

		// �摜��`��
		DrawRotaGraph(tempPos.x, tempPos.y, 1.0f, DX_PI_F / 2, statusImage[vectorArray[i]], TRUE);
	}
}