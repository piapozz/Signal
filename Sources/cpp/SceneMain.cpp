#include "../header/SceneMain.h"

SceneMain::SceneMain() 
{
    gameManager = new GameManager();
}

SceneMain::~SceneMain() 
{

}

void SceneMain::Init() 
{
    // ������
    gameManager->Init();
}

void SceneMain::Proc()
{
    // ���́@����
    gameManager->Proc();
}

int SceneMain::CheckChangeScene() 
{

    return sceneName;
}

void SceneMain::Draw() 
{
    // �`��
    gameManager->Draw();
}