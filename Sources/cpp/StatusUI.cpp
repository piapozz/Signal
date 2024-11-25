#include "../header/StatusUI.h"

StatusUI::StatusUI(BulletManager* bulletManager, Vector2 position)
{
	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("Resources/Bullet_2.png");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("Resources/Bullet_1.png");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("");
	bulletIcon[(int)BulletType::TRACKING_SHOT] = LoadGraph("");

	bulletStateText[(int)BulletStatus::SPEED] = "SPEED";
	bulletStateText[(int)BulletStatus::POWER] = "POWER";
	bulletStateText[(int)BulletStatus::RANGE] = "RANGE";
	bulletStateText[(int)BulletStatus::RATE] = "RATE";

	// �����ʒu���X�V
	initPos = position;

	bullet = bulletManager;
}

StatusUI::~StatusUI()
{

}

void StatusUI::ArrangeIcon()
{
	Vector2 infoPos;

	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		infoPos.x += BULLET_ICON_HEIGHT * i;
		infoPos.y += BULLET_ICON_WIDTH * i;

		DrawExtendGraph(initPos.x, initPos.y, initPos.x * 2, initPos.y * 2, bulletIcon[i], TRUE);
	}
}

void StatusUI::BulletLevel()
{

}

// �e�̃X�e�[�^�X��`��
void StatusUI::StatusViewer(int deviceNum)
{
	Vector2 infoPos;

	// �����̏����ʒu
	infoPos.y = initPos.y;

	int textError = 0;

	// �����Ɛ��̊Ԃ̋󔒂̒����𕶎�������ԑ����l�ɒ���
	for (int i = 0; i < (int)BulletStatus::MAX; i++) if (textError <= bulletStateText[i].size())textError = bulletStateText[i].size();

	// �X�e�[�^�X�̏�Ԃ𐯂ŕ`��
	for (int i = 0; i < (int)BulletStatus::MAX; i++)
	{
		infoPos.x = initPos.x;
		infoPos.y += 20.0f;

		// �X�e�[�^�X��
		DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, bulletStateText[i].c_str());

		// �X�e�[�^�X�̒l�ɂ���Đ���`��
		for (int j = 0; j < 5; j++)
		{
			infoPos.x = initPos.x;
			// 
			infoPos.x += j * STAR_TO_STAR + textError * TEXT_TO_STAR;
			// �X�e�[�^�X�̃��x�����ui�v�𒴂��Ă����獕���ŕ`��
			if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "��"); }
			// �����Ă��Ȃ������甒���ŕ`��
			else DrawFormatString(infoPos.x, infoPos.y, COLOR_WHITE, "��");
		}
	}
}

// �v���C���[�̎���ɃX�e�[�^�X��`��
void StatusUI::PlayerAround(std::vector<int> vectorArray, Vector2 playerPos)
{
	Vector2 tempPos;

	// �z��̕��v���C���[�̎����UI��`��
	for (int i = 0; i < vectorArray.size(); i++)
	{
		// �ui�v�̏�Ԃ����ĕ��p�𕪊� ���k���쐼�̏��Ԃŕ`��
		switch (i)
		{
		case (int)Cardinal::WEST:
			tempPos.x = -DISTANCE_ERROR;
			tempPos.y = 0.0f;

			break;
		case (int)Cardinal::NORTH:
			tempPos.x = 0.0f;
			tempPos.y = -DISTANCE_ERROR;

			break;
		case (int)Cardinal::EAST:
			tempPos.x = DISTANCE_ERROR;
			tempPos.y = 0.0f;

			break;
		case (int)Cardinal::SOUTH:
			tempPos.x = 0.0f;
			tempPos.y = DISTANCE_ERROR;

			break;
		}

		// �v���C���[������p�ɍ��킹��
		tempPos = tempPos + playerPos;

		// �摜��`��
		DrawRotaGraph(tempPos.x, tempPos.y, 1.0f, DX_PI_F / 2, bulletIcon[vectorArray[i]], TRUE);
	}
}