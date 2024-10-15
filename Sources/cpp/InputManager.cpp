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

	if (_inputParam[playerNum - 1].Buttons[(int)button] != 0)
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
		temp.x = (float)_inputParam[playerNum - 1].X;
		temp.y = (float)_inputParam[playerNum - 1].Y;
		break;

	case Stick::RIGHT:
		temp.x = (float)_inputParam[playerNum - 1].Z;
		temp.y = (float)_inputParam[playerNum - 1].Rz;
		break;
	default: break;
	}

	return temp;
}

// �����ꂽ�u�Ԃ���true��Ԃ��֐�
bool InputManager::CheckDownButton(int playerNum, Button button)
{
	// ����
	bool result = false;

	// ���݂̃L�[�̏��
	bool buttonState = false;
	if (_inputParam[playerNum - 1].Buttons[(int)button] != 0)
		buttonState = true;

	// �O��̃L�[��������ĂȂ��A���݉����ꂽ�Ƃ�
	if ((_downBuffer[playerNum][(int)button] == false) && (buttonState == true))
		result = true;

	// ���݂̃L�[��Ԃ��o�b�t�@�Ɋi�[
	_downBuffer[playerNum][(int)button] = buttonState;

	return result;
}