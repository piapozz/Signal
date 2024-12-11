#pragma once
#include "Const.h"
#include "DxLib.h"

class InputManager
{
private:

	DINPUT_JOYSTATE _inputParam[PLAYER_MAX];		// ���͏��̍\����

	bool _downBuffer[PLAYER_MAX][32];		// �L�[�̓��͏���ۑ�����o�b�t�@
	bool _downDirBuffer[PLAYER_MAX][4];
	int _inputControllerNum;				// �R���g���[���[�̐ڑ���

public:

	InputManager();
	~InputManager() {}

	void Proc();
	// �ڑ��R���g���[���[�̐���Ԃ��֐�
	inline int GetPlayerNum() const { return _inputControllerNum; }
	// ������Ă��邩�Ԃ��֐�
	inline bool GetButton(const int& playerNum, const Button& button) const { return _inputParam[playerNum].Buttons[(int)button]; }
	bool GetDirButton(const int& playerNum, const DirButton& dirButton);
	Vector2 GetStick(const int& playerNum, const Stick& stick);
	bool CheckDownButton(const int& playerNum, const Button& button);
	bool CheckDownDirButton(const int& playerNum, const DirButton& dirButton);
	void UpdateBuffer();
};