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
    // ‰Šú‰»
    gameManager->Init();
}

void SceneMain::Proc()
{
    // “ü—Í@ˆ—
    gameManager->Proc();
}

int SceneMain::CheckChangeScene() 
{

    return sceneName;
}

void SceneMain::Draw() 
{
    // •`‰æ
    gameManager->Draw();
}