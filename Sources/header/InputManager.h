#pragma once
#include "Const.h"

class InputManager
{
private:

	DINPUT_JOYSTATE inputParam[PLAYER_MAX];		// ���͏��̍\����

	bool downBuffer[PLAYER_MAX][32];		// �L�[�̓��͏���ۑ�����o�b�t�@

	int inputControllerNum;		// �R���g���[���[�̐ڑ���

public:

	InputManager() {}
	~InputManager() {}

	void Proc();
	bool GetButton(int playerNum, BUTTON button);
	Vector2 GetStick(int playerNum, STICK stick);
	bool CheckDownButton(int playerNum, BUTTON button);
};