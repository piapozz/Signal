#pragma once
#include "Const.h"
#include "InputManager.h"
#include "AudioManager.h"
using namespace std;

// �V�[���̊�{�N���X
class BaseScene 
{
protected:

	// �R���g���[���[�̓���
	InputManager* input;

public:
	// �V�[���̖��O
	enum SceneName
	{
		NONE = 0,
		GAME_TITLE,
		GAME_MAIN,
		GAME_RESULT,
		GAME_OPTION,
		GAME_EXIT,

		MAX
	};


	BaseScene();
	virtual ~BaseScene();

	// ������
	virtual void Init() = 0;

	// �����Ɋ֘A������e���L�q����
	virtual void Proc() = 0;

	// �`��Ɋ֘A������e���L�q����
	virtual void Draw() = 0;

	// �V�[���̐؂�ւ�
	virtual int CheckChangeScene() = 0;

	//void DrawString(string text, Vector2 position);
};
