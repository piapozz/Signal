#include "../header/InputManager.h"
#include "DxLib.h"

namespace CheckKey
{
	bool downBuffer[256];	// �L�[�̓��͏���ۑ�����o�b�t�@
}

void InputManager::Proc()
{
	// �ڑ�����Ă�R���g���[���[�̐��𒲂ׂ�
	inputControllerNum = GetJoypadNum();

	// �R���g���[���[�̐���������
	for (int i = DX_INPUT_PAD1; i <= DX_INPUT_PAD1 + inputControllerNum; i++)
	{
		DINPUT_JOYSTATE input;

		GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

		upFlag = GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP;

	}
}

bool InputManager::CheckDownButton(int playerNum, int button)
{
	// ����
	bool result = 0;

	// ���݂̃L�[�̏��
	bool buttonState = inputParam[playerNum - 1].;
	bool keyState = CheckHitKey(button);

	// �O��̃L�[��������ĂȂ��A���݉����ꂽ�Ƃ�
	if ((CheckKey::downBuffer[button] == false) && (keyState == true))
	{
		result = true;
	}

	// ���݂̃L�[��Ԃ��o�b�t�@�Ɋi�[
	CheckKey::downBuffer[button] = keyState;

	return result;
}