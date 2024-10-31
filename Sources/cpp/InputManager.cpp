#include "../header/InputManager.h"

void InputManager::Proc()
{
	// �ڑ�����Ă�R���g���[���[�̐��𒲂ׂ�
	_inputControllerNum = GetJoypadNum();
	printfDx("�ڑ��R���g���[���[%d\n", _inputControllerNum);

	// �R���g���[���[�̐���������
	for (int i = 0; i < _inputControllerNum; i++)
	{
		// �R���g���[���[�̓��͏����\���̂ɑ��
		int result = GetJoypadDirectInputState(i + DX_INPUT_PAD1, &_inputParam[i]);

		printfDx("�v���C���[%d\n", i + 1);
		printfDx("LX:%d\n", _inputParam[i].X);
		printfDx("LY:%d\n", _inputParam[i].Y);
		printfDx("RX:%d\n", _inputParam[i].Z);
		printfDx("RY:%d\n", _inputParam[i].Rz);
		printfDx("RT:%d\n", _inputParam[i].Buttons[(int)Button::RIGHT_TRIGGER]);
	}
}

// �ڑ��R���g���[���[�̐���Ԃ��֐�
int InputManager::GetPlayerNum()
{
	return _inputControllerNum;
}

// ������Ă��邩�Ԃ��֐�
bool InputManager::GetButton(int playerNum, Button button)
{
	bool result = false;

	if (_inputParam[playerNum ].Buttons[(int)button] != 0)
		result = true;

	return result;
}

// �X�e�B�b�N�̓��͏����擾����֐�
Vector2 InputManager::GetStick(int playerNum, Stick stick)
{
	Vector2 temp;

	switch (stick)
	{
	case Stick::LEFT:
		temp.x = (float)_inputParam[playerNum].X;
		temp.y = (float)_inputParam[playerNum].Y;
		break;

	case Stick::RIGHT:
		temp.x = (float)_inputParam[playerNum ].Z;
		temp.y = (float)_inputParam[playerNum ].Rz;
		break;
	default: break;
	}

	printfDx("temp.x%f\n", temp.x);
	printfDx("temp.y%f\n", temp.y);
	printfDx("num%d\n", playerNum);

	return temp;
}

// �����ꂽ�u�Ԃ���true��Ԃ��֐�
bool InputManager::CheckDownButton(int playerNum, Button button)
{
	// ����
	bool result = false;

	// ���݂̃L�[�̏��
	bool buttonState = false;
	if (_inputParam[playerNum ].Buttons[(int)button] != 0)
		buttonState = true;

	// �O��̃L�[��������ĂȂ��A���݉����ꂽ�Ƃ�
	if ((_downBuffer[playerNum][(int)button] == false) && (buttonState == true))
		result = true;

	// ���݂̃L�[��Ԃ��o�b�t�@�Ɋi�[
	_downBuffer[playerNum][(int)button] = buttonState;

	return result;
}