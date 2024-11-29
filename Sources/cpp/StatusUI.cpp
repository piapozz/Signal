#include "../header/StatusUI.h"

// �F�X�Ȃ��̂�����������
StatusUI::StatusUI(BulletManager* bulletManager, Vector2 position)
{
	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("Resources/Bullet_Normal.png");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("Resources/Bullet_Explosion.png");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("Resources/Bullet_MultiShot.png");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("Resources/Bullet_Penetration.png");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("Resources/Bullet_Reflection.png");
	bulletIcon[(int)BulletType::TRACKING_SHOT] = LoadGraph("");

	bulletStateText[(int)BulletStatus::SPEED] = "SPEED";
	bulletStateText[(int)BulletStatus::POWER] = "POWER";
	bulletStateText[(int)BulletStatus::RANGE] = "RANGE";
	bulletStateText[(int)BulletStatus::RATE] = "RATE";

	levelViewIcon = LoadGraph("Resources/Bullet_Level_Bar.png");

	// �����ʒu���X�V
	initPos = position;

	// bulletManager���p���Ȃ���擾
	bullet = bulletManager;
}

StatusUI::~StatusUI()
{

}

// �A�C�R���Ƃ��̒e�̃��x����`��
void StatusUI::ArrangeIcon(int deviceNum)
{
	// �`�悷����W�̍���̒��_���W��������
	Vector2 infoPos = initPos;
	Vector2 barPos;

	infoPos.x -= BULLET_ICON_HEIGHT;

	// �e�̎�ނ�`��
	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		infoPos.x += BULLET_ICON_HEIGHT;
		// infoPos.y += BULLET_ICON_WIDTH * ;

		// �`��
		DrawExtendGraph(infoPos.x, infoPos.y, infoPos.x + BULLET_ICON_HEIGHT, infoPos.y + BULLET_ICON_WIDTH, bulletIcon[i], TRUE);

		// �e�̃��x���o�[��`��
		for (int j = 0; j < LEVEL_MAX; j++)
		{
			// �Ԋu�𒲐߂��邽�߂̕ϐ�
			Vector2 distanceError;

			// �萔���g����x,y���ꂼ��̌덷������������
			//distanceError.x = j * LEVEL_BAR_HEIGHT;
			//distanceError.y = j * LEVEL_BAR_WIDTH;

			barPos = infoPos;

			// �����𒲐�
			barPos.y += BULLET_ICON_WIDTH + LEVEL_BAR_WIDTH;

			// �e�̃��x�������ă��x�������x���o�[��`�悷��
			if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i])
			{
				barPos.y += LEVEL_BAR_WIDTH;
				// ���x���o�[��`��
				DrawExtendGraph(barPos.x, barPos.y , barPos.x + BULLET_ICON_HEIGHT, barPos.y + LEVEL_BAR_WIDTH, levelViewIcon, TRUE);
			}
		}
	}
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
		for (int j = 0; j < 10; j++)
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
	Vector2 centerPos;

	// �z��̕��v���C���[�̎����UI��`��
	for (int i = 0; i < vectorArray.size(); i++)
	{
		// �ui�v�̏�Ԃ����ĕ��p�𕪊� ���k���쐼�̏��Ԃŕ`��
		switch (i)
		{
		case (int)Cardinal::WEST:
			centerPos.x = -DISTANCE_ERROR;
			centerPos.y = 0.0f;

			break;
		case (int)Cardinal::NORTH:
			centerPos.x = 0.0f;
			centerPos.y = -DISTANCE_ERROR;

			break;
		case (int)Cardinal::EAST:
			centerPos.x = DISTANCE_ERROR;
			centerPos.y = 0.0f;

			break;
		case (int)Cardinal::SOUTH:
			centerPos.x = 0.0f;
			centerPos.y = DISTANCE_ERROR;

			break;
		}

		// �v���C���[������p�ɍ��킹��
		centerPos = centerPos + playerPos;

		// �摜��`��
		// DrawRotaGraph(tempPos.x, tempPos.y, 1.0f, DX_PI_F / 2, bulletIcon[vectorArray[i]], TRUE);

		DrawExtendGraph(centerPos.x - TYPE_ICON.x, centerPos.y - TYPE_ICON.y, centerPos.x + TYPE_ICON.x, centerPos.y + TYPE_ICON.y, bulletIcon[vectorArray[i]], TRUE);
	}
}