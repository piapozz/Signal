#include "../header/InputManager.h"
#include "DxLib.h"

namespace CheckKey
{
	bool downBuffer[256];	// �L�[�̓��͏���ۑ�����o�b�t�@
}

void InputManager::Proc()
{

}

bool InputManager::CheckDownKey(int key)
{
	// ����
	bool result = 0;

	// ���݂̃L�[�̏��
	bool keyState = CheckHitKey(key);

	// �O��̃L�[��������ĂȂ��A���݉����ꂽ�Ƃ�
	if ((CheckKey::downBuffer[key] == false) && (keyState == true))
	{
		result = true;
	}

	// ���݂̃L�[��Ԃ��o�b�t�@�Ɋi�[
	CheckKey::downBuffer[key] = keyState;

	return result;
}