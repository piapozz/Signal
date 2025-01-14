#include "../header/UIManager.h"

UIManager::UIManager()
{
	initPos[0] = { 0.0f,25.0f };
	initPos[1] = { 1500.0f,25.0f };
	// initPos[2] = { 1500.0f,25.0f };
	// initPos[2] = { 0.0f,750.0f };
	// initPos[3] = { 1500,750.0f };

	bulletIcon[(int)BulletType::NORMAL] = LoadGraph("Resources/Bullet_Normal.png");
	bulletIcon[(int)BulletType::EXPLOSION] = LoadGraph("Resources/Bullet_Explosion.png");
	bulletIcon[(int)BulletType::MULTI_SHOT] = LoadGraph("Resources/Bullet_MultiShot.png");
	bulletIcon[(int)BulletType::PENETRATION] = LoadGraph("Resources/Bullet_Penetration.png");
	bulletIcon[(int)BulletType::REFLECTION] = LoadGraph("Resources/Bullet_Reflection.png");

	statusIcon[(int)BulletStatus::SPEED] = LoadGraph("Resources/Status_Speed.png");
	statusIcon[(int)BulletStatus::POWER] = LoadGraph("Resources/Status_Power.png");
	statusIcon[(int)BulletStatus::RANGE] = LoadGraph("Resources/Status_Range.png");
	statusIcon[(int)BulletStatus::RATE] = LoadGraph("Resources/Status_Rate.png");
}

UIManager::~UIManager()
{

}

void UIManager::Init(BulletManager* bulletManager, std::vector<BaseCharacter*> devicesObject)
{
	bullet = bulletManager;

	// �f�o�C�X�̏�Ԃ�ێ�
	devices = devicesObject;

	// UI�{�̂𐶐�
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		statusUI.push_back(new StatusUI(bullet, initPos[i]));
	}
}

void UIManager::Proc()
{

}

void UIManager::Draw()
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		// �擾���Ă���ˌ��^�C�v���摜�ŏ��Ԃɕ��ׂ�
		statusUI[i]->ArrangeIcon(devices[i]->deviceNum,bulletIcon);

		// �X�e�[�^�X�̏�Ԃ𐯂ŕ`��
		statusUI[i]->StatusViewer(devices[i]->deviceNum);

		// ���x���A�b�v�����Ƃ��������镨��\��

		// �t���O�̏�Ԃ��擾
		flagStatus = devices[i]->GetChooceFlag();

		if (flagStatus == 1)
		{
			statusUI[i]->PlayerAround(devices[i]->choicePower, devices[i]->GetDisplayPos(), bulletIcon);
		}
		else if (flagStatus == 2)
		{
			statusUI[i]->PlayerAround(devices[i]->choiceStatus, devices[i]->GetDisplayPos(), statusIcon);
		}

		// ���x���̕\��
		statusUI[i]->PlayerLevel(devices[i]->levelUpCount);

		// �o���l/�K�v�� �̕\��
		statusUI[i]->RequestCount(devices[i]->GetExpValue(), devices[i]->GetRequestValue());
	}

	TutorialDraw();
}

void UIManager::TutorialDraw()
{
	DrawFormatString(1700, 980, COLOR_WHITE, "���X�e�B�b�N�F�ړ�");
	DrawFormatString(1700, 1000, COLOR_WHITE, "�E�X�e�B�b�N�F��]");
	DrawFormatString(1700, 1020, COLOR_WHITE, "���g���K�[�F���");
	DrawFormatString(1700, 1040, COLOR_WHITE, "�E�g���K�[�F�ˌ�");
	DrawFormatString(1700, 1060, COLOR_WHITE, "�E�{�^���F�X�L���I��");
}