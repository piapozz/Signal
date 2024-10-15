#include "../header/InputManager.h"

void InputManager::Proc()
{
	// 接続されてるコントローラーの数を調べる
	_inputControllerNum = GetJoypadNum();
	printfDx("接続コントローラー%d\n", _inputControllerNum);

	// コントローラーの数だけ処理
	for (int i = 0; i < _inputControllerNum; i++)
	{
		// コントローラーの入力情報を構造体に代入
		int result = GetJoypadDirectInputState(i + DX_INPUT_PAD1, &_inputParam[i]);
	}
}

// 接続コントローラーの数を返す関数
int InputManager::GetPlayerNum()
{
	return _inputControllerNum;
}

// 押されているか返す関数
bool InputManager::GetButton(int playerNum, Button button)
{
	bool result = false;

	if (_inputParam[playerNum - 1].Buttons[(int)button] != 0)
		result = true;

	return result;
}

// スティックの入力情報を取得する関数
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

// 押された瞬間だけtrueを返す関数
bool InputManager::CheckDownButton(int playerNum, Button button)
{
	// 結果
	bool result = false;

	// 現在のキーの状態
	bool buttonState = false;
	if (_inputParam[playerNum - 1].Buttons[(int)button] != 0)
		buttonState = true;

	// 前回のキーが押されてなく、現在押されたとき
	if ((_downBuffer[playerNum][(int)button] == false) && (buttonState == true))
		result = true;

	// 現在のキー状態をバッファに格納
	_downBuffer[playerNum][(int)button] = buttonState;

	return result;
}