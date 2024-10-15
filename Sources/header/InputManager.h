#pragma once
#include "Const.h"
#include "DxLib.h"

class InputManager
{
private:

	DINPUT_JOYSTATE _inputParam[PLAYER_MAX];		// 入力情報の構造体

	bool _downBuffer[PLAYER_MAX][32];		// キーの入力情報を保存するバッファ

	int _inputControllerNum;		// コントローラーの接続数

public:

	InputManager() {}
	~InputManager() {}

	void Proc();
	int GetPlayerNum();
	bool GetButton(int playerNum, Button button);
	Vector2 GetStick(int playerNum, Stick stick);
	bool CheckDownButton(int playerNum, Button button);
};