#include "../header/InputManager.h"

InputManager::InputManager()
{
	Proc();
}

void InputManager::Proc()
{
	UpdateBuffer();

	// �ڑ�����Ă�R���g���[���[�̐��𒲂ׂ�
	_inputControllerNum = GetJoypadNum();

	// �R���g���[���[�̐���������
	for (int i = 0; i < _inputControllerNum; i++)
	{
		// �R���g���[���[�̓��͏����\���̂ɑ��
		GetJoypadDirectInputState(i + DX_INPUT_PAD1, &_inputParam[i]);
	}
}

// �X�e�B�b�N�̓��͏��𐳋K�����Ď擾����֐�
Vector2 InputManager::GetStick(const int& playerNum, const Stick& stick)
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

	temp.normalize();

	return temp;
}

// �����ꂽ�u�Ԃ���true��Ԃ��֐�
bool InputManager::CheckDownButton(const int& playerNum, const Button& button)
{
	// ����
	bool result = false;

	// ���݂̃L�[�̏��
	bool buttonState = GetButton(playerNum, button);

	// �O��̃L�[��������ĂȂ��A���݉����ꂽ�Ƃ�
	if ((_downBuffer[playerNum][(int)button] == false) && (buttonState == true))
		result = true;

	return result;
}

bool InputManager::GetDirButton(const int& playerNum, const DirButton& dirButton)
{
	// �p�x����x�̃{�^����������Ă��邩����
	int input = _inputParam[playerNum].POV[0];
	if (input == -1)
		return false;
	float angle = input / 100 / RAD;
	float x = sinf(angle);
	float y = cosf(angle);
	switch (dirButton)
	{
	case DirButton::UP:
		if (y > 0.01f)
			return true;
		break;
	case DirButton::RIGHT:
		if (x > 0.01f)
			return true;
		break;
	case DirButton::DOWN:
		if (y < -0.01f)
			return true;
		break;
	case DirButton::LEFT:
		if (x < -0.01f)
			return true;
		break;
	default: break;
	}
	return false;
}

bool InputManager::CheckDownDirButton(const int& playerNum, const DirButton& dirButton)
{
	// ����
	bool result = false;

	// ���݂̃L�[�̏��
	bool buttonState = GetDirButton(playerNum, dirButton);

	// �O��̃L�[��������ĂȂ��A���݉����ꂽ�Ƃ�
	if ((_downDirBuffer[playerNum][(int)dirButton] == false) && (buttonState == true))
		result = true;

	return result;
}

void InputManager::UpdateBuffer()
{
	for (int p = 0; p < _inputControllerNum; p++)
	{
		// �{�^��
		for (int i = 0; i < 32; i++)
		{
			_downBuffer[p][i] = GetButton(p, (Button)i);
		}

		// �\��
		for (int i = 0; i < 4; i++)
		{
			_downDirBuffer[p][i] = GetDirButton(p, (DirButton)i);
		}
	}
}