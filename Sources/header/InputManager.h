#pragma once
#include "Const.h"
#include "DxLib.h"

class InputManager
{
private:

	DINPUT_JOYSTATE _inputParam[PLAYER_MAX];		// ���͏��̍\����

	bool _downBuffer[PLAYER_MAX][32];		// �L�[�̓��͏���ۑ�����o�b�t�@

	int _inputControllerNum;		// �R���g���[���[�̐ڑ���

public:

	InputManager() {}
	~InputManager() {}

	void Proc();
	int GetPlayerNum();
	bool GetButton(int playerNum, Button button);
	Vector2 GetStick(int playerNum, Stick stick);
	bool CheckDownButton(int playerNum, Button button);
};