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

		printfDx("プレイヤー%d\n", i + 1);
		printfDx("LX:%d\n", _inputParam[i].X);
		printfDx("LY:%d\n", _inputParam[i].Y);
		printfDx("RX:%d\n", _inputParam[i].Z);
		printfDx("RY:%d\n", _inputParam[i].Rz);
		printfDx("RT:%d\n", _inputParam[i].Buttons[(int)Button::RIGHT_TRIGGER]);
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

	if (_inputParam[playerNum ].Buttons[(int)button] != 0)
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
		temp.x = (float)_inputParam[playerNum].X;
		temp.y = (float)_inputParam[playerNum].Y;
		break;

	case Stick::RIGHT:
		temp.x = (float)_inputParam[playerNum ].Z;
		temp.y = (float)_inputParam[playerNum ].Rz;
		break;
	default: break;
	}

	printfDx("temp.x%f\n", temp.x);
	printfDx("temp.y%f\n", temp.y);
	printfDx("num%d\n", playerNum);

	return temp;
}

// 押された瞬間だけtrueを返す関数
bool InputManager::CheckDownButton(int playerNum, Button button)
{
	// 結果
	bool result = false;

	// 現在のキーの状態
	bool buttonState = false;
	if (_inputParam[playerNum ].Buttons[(int)button] != 0)
		buttonState = true;

	// 前回のキーが押されてなく、現在押されたとき
	if ((_downBuffer[playerNum][(int)button] == false) && (buttonState == true))
		result = true;

	// 現在のキー状態をバッファに格納
	_downBuffer[playerNum][(int)button] = buttonState;

	return result;
}