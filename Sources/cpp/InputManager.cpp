#include "../header/InputManager.h"
#include "DxLib.h"

void InputManager::Proc()
{
	// �ڑ�����Ă�R���g���[���[�̐��𒲂ׂ�
	inputControllerNum = GetJoypadNum();

	// �R���g���[���[�̐���������
	for (int i = DX_INPUT_PAD1; i <= DX_INPUT_PAD1 + inputControllerNum; i++)
	{
		// �R���g���[���[�̓��͏����\���̂ɑ��
		GetJoypadDirectInputState(i, &inputParam[i]);
	}
}

// ������Ă��邩�Ԃ��֐�
bool InputManager::GetButton(int playerNum, BUTTON button)
{
	return inputParam[playerNum - 1].Buttons[button];
}

// �X�e�B�b�N�̓��͏����擾����֐�
Vector2 InputManager::GetStick(int playerNum, STICK stick)
{
	Vector2 temp;

	switch (stick)
	{
	case LEFT:
		temp.x = inputParam[playerNum - 1].X;
		temp.y = inputParam[playerNum - 1].Y;
		break;

	case RIGHT:
		temp.x = inputParam[playerNum - 1].X;
		temp.y = inputParam[playerNum - 1].Y;
		break;
	default: break;
	}

	return temp;
}

// �����ꂽ�u�Ԃ���true��Ԃ��֐�
bool InputManager::CheckDownButton(int playerNum, BUTTON button)
{
	// ����
	bool result = false;

	// ���݂̃L�[�̏��
	bool buttonState = inputParam[playerNum - 1].Buttons[button];

	// �O��̃L�[��������ĂȂ��A���݉����ꂽ�Ƃ�
	if ((downBuffer[playerNum][button] == false) && (buttonState == true))
		result = true;

	// ���݂̃L�[��Ԃ��o�b�t�@�Ɋi�[
	downBuffer[playerNum][button] = buttonState;

	return result;
}