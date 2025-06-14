#include "../header/SceneMain.h"

SceneMain::SceneMain() 
{
    gameManager = new GameManager(input);
}

SceneMain::~SceneMain() 
{

}

void SceneMain::Init() 
{
    // 初期化
    gameManager->Init();
}

void SceneMain::Proc()
{
    // 入力　処理
    gameManager->Proc();


}

int SceneMain::CheckChangeScene() 
{
    // ゲームが終了していたらシーンを遷移
    if (gameManager->GetFinish() == true)
    {
        AudioManager::GetInstance().PlaySE(SEName::GAMEEND);
        sceneName = SceneName::GAME_RESULT;

    }

    return sceneName;
}

void SceneMain::Draw() 
{
    // 描画
    gameManager->Draw();
}