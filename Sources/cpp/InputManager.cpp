#include "../header/InputManager.h"
#include "DxLib.h"

namespace CheckKey
{
	bool downBuffer[256];	// キーの入力情報を保存するバッファ
}

void InputManager::Proc()
{
	// 接続されてるコントローラーの数を調べる
	inputControllerNum = GetJoypadNum();

	// コントローラーの数だけ処理
	for (int i = DX_INPUT_PAD1; i <= DX_INPUT_PAD1 + inputControllerNum; i++)
	{
		DINPUT_JOYSTATE input;

		GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

		upFlag = GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP;

	}
}

bool InputManager::CheckDownButton(int playerNum, int button)
{
	// 結果
	bool result = 0;

	// 現在のキーの状態
	bool buttonState = inputParam[playerNum - 1].;
	bool keyState = CheckHitKey(button);

	// 前回のキーが押されてなく、現在押されたとき
	if ((CheckKey::downBuffer[button] == false) && (keyState == true))
	{
		result = true;
	}

	// 現在のキー状態をバッファに格納
	CheckKey::downBuffer[button] = keyState;

	return result;
}