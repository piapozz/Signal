#include "../header/InputManager.h"
#include "DxLib.h"

void InputManager::Proc()
{
	// 接続されてるコントローラーの数を調べる
	inputControllerNum = GetJoypadNum();

	// コントローラーの数だけ処理
	for (int i = DX_INPUT_PAD1; i <= DX_INPUT_PAD1 + inputControllerNum; i++)
	{
		// コントローラーの入力情報を構造体に代入
		GetJoypadDirectInputState(i, &inputParam[i]);
	}
}

// 押されているか返す関数
bool InputManager::GetButton(int playerNum, BUTTON button)
{
	return inputParam[playerNum - 1].Buttons[button];
}

// スティックの入力情報を取得する関数
Vector2 InputManager::GetStick(int playerNum, STICK stick)
{
	Vector2 temp;

	switch (stick)
	{
	case LEFT:
		temp.x = inputParam[playerNum - 1].X;
		temp.y = inputParam[playerNum - 1].Y;
		break;

	case RIGHT:
		temp.x = inputParam[playerNum - 1].X;
		temp.y = inputParam[playerNum - 1].Y;
		break;
	default: break;
	}

	return temp;
}

// 押された瞬間だけtrueを返す関数
bool InputManager::CheckDownButton(int playerNum, BUTTON button)
{
	// 結果
	bool result = false;

	// 現在のキーの状態
	bool buttonState = inputParam[playerNum - 1].Buttons[button];

	// 前回のキーが押されてなく、現在押されたとき
	if ((downBuffer[playerNum][button] == false) && (buttonState == true))
		result = true;

	// 現在のキー状態をバッファに格納
	downBuffer[playerNum][button] = buttonState;

	return result;
}