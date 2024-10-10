#include "DxLib.h"
#include "../header/SceneManager.h"

// �v���O�����J�n
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�C���h�E���[�h�ŋN��
	ChangeWindowMode(true);

	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);

	// �𑜓x��ݒ�
	//SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}

	// �V�[���}�l�[�W���[����
	SceneManager* sceneManager = new SceneManager();

	// ������
	sceneManager->ChangeScene(BaseScene::MAIN);

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �J�����̈ʒu�ƌ�����ݒ�
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 250.0f, -250.0f), VGet(0.0f, 0.0f, 0.0f));

	// �J�����̃N���b�s���O������ݒ�
	SetCameraNearFar(16.0f, 10000.0f);

	// �w�i�̐F���D�F�ɂ���
	//SetBackgroundColor(128, 128, 128);

	// Z�o�b�t�@���g�p����
	SetUseZBufferFlag(true);
	SetWriteZBufferFlag(true);

	// ���C�����[�v(�����L�[�������ꂽ�烋�[�v�𔲂���)
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ���݂̃J�E���g���擾����
		int time = GetNowCount();

		// ��ʂ̃N���A
		ClearDrawScreen();
		clsDx();

		// �V�[��������
		sceneManager->Proc();

		// �V�[���̕`��
		sceneManager->Draw();
		

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		// �P�V�~���b(��b�ԂU�O�t���[�����������̂P�t���[��������̌o�ߎ���)
		// �o�߂���܂ł����ő҂�
		while (GetNowCount() - time < 17)
		{
		}
	}

	// �V�[���}�l�[�W���[�̍폜
	//delete sceneManager;

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}