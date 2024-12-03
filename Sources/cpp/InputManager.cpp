#include "../header/InputManager.h"

void InputManager::Proc()
{
	UpdateBuffer();

	// 接続されてるコントローラーの数を調べる
	_inputControllerNum = GetJoypadNum();

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

	if (_inputParam[playerNum].Buttons[(int)button] != 0)
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

	temp.normalize();

	return temp;
}

// 押された瞬間だけtrueを返す関数
bool InputManager::CheckDownButton(int playerNum, Button button)
{
	// 結果
	bool result = false;

	// 現在のキーの状態
	bool buttonState = GetButton(playerNum, button);

	// 前回のキーが押されてなく、現在押されたとき
	if ((_downBuffer[playerNum][(int)button] == false) && (buttonState == true))
		result = true;

	return result;
}

bool InputManager::GetDirButton(int playerNum, DirButton dirButton)
{
	// 角度から度のボタンが押されているか判定
	int input = _inputParam[playerNum].POV[0];
	if (input == -1)
		return false;
	float angle = input / 100 / RAD;
	float x = sinf(angle);
	float y = cosf(angle);
	switch (dirButton)
	{
	case DirButton::UP:
		if (y > 0.01f)
			return true;
		break;
	case DirButton::RIGHT:
		if (x > 0.01f)
			return true;
		break;
	case DirButton::DOWN:
		if (y < -0.01f)
			return true;
		break;
	case DirButton::LEFT:
		if (x < -0.01f)
			return true;
		break;
	default: break;
	}
	return false;
}

bool InputManager::CheckDownDirButton(int playerNum, DirButton dirButton)
{
	// 結果
	bool result = false;

	// 現在のキーの状態
	bool buttonState = GetDirButton(playerNum, dirButton);

	// 前回のキーが押されてなく、現在押されたとき
	if ((_downDirBuffer[playerNum][(int)dirButton] == false) && (buttonState == true))
		result = true;

	return result;
}

void InputManager::UpdateBuffer()
{
	for (int p = 0; p < _inputControllerNum; p++)
	{
		// ボタン
		for (int i = 0; i < 32; i++)
		{
			_downBuffer[p][i] = GetButton(p, (Button)i);
		}

		// 十字
		for (int i = 0; i < 4; i++)
		{
			_downDirBuffer[p][i] = GetDirButton(p, (DirButton)i);
		}
	}
}