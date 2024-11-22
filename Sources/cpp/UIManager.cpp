#include "../header/UIManager.h"

UIManager::UIManager()
{
	initPos[0] = { 0.0f,25.0f };
	initPos[1] = { 1500.0f,25.0f };
	// initPos[2] = { 0.0f,750.0f };
	// initPos[3] = { 1500,750.0f };
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

		// �擾���Ă���ˌ��^�C�v�̉��Ƀ��x����\������

		// �X�e�[�^�X�̏�Ԃ𐯂ŕ`��
		statusUI[i]->StatusViewer(devices[i]->deviceNum);

		// ���x���A�b�v�����Ƃ��������镨��\��

		// �t���O�̏�Ԃ��擾
		flagStatus = devices[i]->GetChooceFlag();

		if (flagStatus == 1)
		{
			statusUI[i]->PlayerAround(devices[i]->choicePower, devices[i]->status.m_position);
		}
		else if (flagStatus == 2)
		{
			statusUI[i]->PlayerAround(devices[i]->choiceStatus, devices[i]->status.m_position);
		}

	}
}