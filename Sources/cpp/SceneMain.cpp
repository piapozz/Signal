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
    // ƒQ[ƒ€‚ªI—¹‚µ‚Ä‚¢‚½‚çƒV[ƒ“‚ð‘JˆÚ
    if (gameManager->CheckFinish() == true)sceneName = SceneName::GAME_RESULT;

    return sceneName;
}

void SceneMain::Draw() 
{
    // •`‰æ
    gameManager->Draw();
}