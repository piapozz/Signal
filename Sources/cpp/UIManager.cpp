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
		infoPos.y += 100;


		DrawFormatString(infoPos.x, infoPos.y, COLOR_BLACK, bulletStateText[i].c_str());

		// �X�e�[�^�X�̒l�ɂ���Đ���`��
		for (int j = 0; j < (int)BulletStatus::MAX; j++)
		{
			if (j < bullet->GetBulletList()[deviceNum].m_BulletStatus[i]) { DrawFormatString(infoPos.x + i * 30, infoPos.y, COLOR_BLACK, "��"); }
			else DrawFormatString(infoPos.x + i * 30, infoPos.y + j * 20, COLOR_BLACK, "��");
		}
	}
}

void UIManager::LevelUpUI()
{
	// ���x���A�b�v�ɕK�v�Ȍ��𖞂����Ă�����
	if (players[i]->GetExpValue() >= players[i]->request)
	{

		// ���x���A�b�v�����玟�̃��x���A�b�v�ɕK�v�ȃR�X�g���グ��
		players[i]->request += 3;

		// �O�̔{���񂱂�܂łɃ��x���A�b�v���Ă�����p���[�A�b�v����I��
		if (players[i]->levelUpCount % 3)
		{
			// �p���[�A�b�v�ł���񐔂��ꂠ����


		}

		// �O�̔{����ł͂Ȃ�������X�e�[�^�X����I��
		else
		{
			// �X�e�[�^�X�A�b�v�ł���񐔂��ꂠ����


		}

	}

	// ���x���A�b�v�ł���񐔂����ăR���g���[���[�̓��͂��󂯎�茋�ʂ𔽉f������
	// �p���[�A�b�v���s��
	if (players[i]->powerUpCount)
	{
		// �񋓑�BulletType�̑傫�����g���ė������擾 
		GetRand((int)BulletType::MAX);


	}

	// �X�e�[�^�X�A�b�v���s��
	else if (players[i]->statusUpCount)
	{

		GetRand((int)BulletStatus::MAX);

	}

}