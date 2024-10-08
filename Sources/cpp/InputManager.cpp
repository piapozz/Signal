#include "../header/InputManager.h"
#include "DxLib.h"

namespace CheckKey
{
	bool downBuffer[256];	// キーの入力情報を保存するバッファ
}

void InputManager::Proc()
{

}

bool InputManager::CheckDownKey(int key)
{
	// 結果
	bool result = 0;

	// 現在のキーの状態
	bool keyState = CheckHitKey(key);

	// 前回のキーが押されてなく、現在押されたとき
	if ((CheckKey::downBuffer[key] == false) && (keyState == true))
	{
		result = true;
	}

	// 現在のキー状態をバッファに格納
	CheckKey::downBuffer[key] = keyState;

	return result;
}