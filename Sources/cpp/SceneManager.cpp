#include "../header/SceneManager.h"

SceneManager::SceneManager() 
{
	_scene = nullptr;
}

SceneManager::~SceneManager() 
{
	if (_exitFlag)return;

	delete(_scene);
}

void SceneManager::Init() 
{
	_scene->Init();
}

void SceneManager::Proc() 
{
	if (_exitFlag)return;

	_scene->Proc();
	ChangeScene(_scene->CheckChangeScene());
}

void SceneManager::Draw() 
{
	if (_exitFlag) return;
		
	_scene->Draw();
}

void SceneManager::ChangeScene(int scene)
{
	if (scene == BaseScene::NONE) return;

	// ���݂̃V�[�����󂶂�Ȃ�������A�V�[���̏���j������
	delete(_scene);

	// �����̃V�[���ɐ؂�ւ���
	switch (scene)
	{
	case BaseScene::GAME_TITLE:
		_scene = new SceneTitle();
		break;
	case BaseScene::GAME_MAIN:
		_scene = new SceneMain();
		break;
	case BaseScene::GAME_RESULT:
		_scene = new SceneResult();
		break;
	case BaseScene::GAME_OPTION:
		break;
	case BaseScene::GAME_EXIT:
		_exitFlag = true;
		return;
	default:
		break;
	}

	// �����������Ă���
	_scene->Init();
}