#pragma once
#include "Const.h"
#include "DxLib.h"

class InputManager
{
private:

	DINPUT_JOYSTATE _inputParam[PLAYER_MAX];		// 入力情報の構造体

	bool _downBuffer[PLAYER_MAX][32];		// キーの入力情報を保存するバッファ
	bool _downDirBuffer[PLAYER_MAX][4];
	int _inputControllerNum;				// コントローラーの接続数

public:

	InputManager();
	~InputManager() {}

	void Proc();
	// 接続コントローラーの数を返す関数
	inline int GetPlayerNum() const { return _inputControllerNum; }
	// 押されているか返す関数
	inline bool GetButton(const int& playerNum, const Button& button) const { return _inputParam[playerNum].Buttons[(int)button]; }
	bool GetDirButton(const int& playerNum, const DirButton& dirButton);
	Vector2 GetStick(const int& playerNum, const Stick& stick);
	bool CheckDownButton(const int& playerNum, const Button& button);
	bool CheckDownDirButton(const int& playerNum, const DirButton& dirButton);
	void UpdateBuffer();
};