#pragma once

// �V�[���̊�{�N���X
#include "../header/BaseScene.h"

#include "../header/SceneTitle.h"
#include "../header/SceneMain.h"
#include "../header/SceneResult.h"

class SceneManager
{
private:

	bool _exitFlag = false;

	// �V�[���̏����i�[
	BaseScene* _scene;

	// �⏕
	void Init();

public:

	SceneManager();
	~SceneManager();

	// main�Ŗ��t���[���Ă΂��
	void Proc();
	void Draw();

	/// �����œn���ꂽ�V�[���ɐ؂�ւ���
	void ChangeScene(int scene);

	bool GetExitFlag() { return _exitFlag; };

};

