#pragma once
#include "Const.h"

class InputManager
{
private:

	DINPUT_JOYSTATE inputParam[PLAYER_MAX];		// 入力情報の構造体

	bool downBuffer[PLAYER_MAX][32];		// キーの入力情報を保存するバッファ

	int inputControllerNum;		// コントローラーの接続数

public:

	InputManager() {}
	~InputManager() {}

	void Proc();
	bool GetButton(int playerNum, BUTTON button);
	Vector2 GetStick(int playerNum, STICK stick);
	bool CheckDownButton(int playerNum, BUTTON button);
};