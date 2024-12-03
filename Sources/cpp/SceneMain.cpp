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
    // �Q�[�����I�����Ă�����V�[����J��
    if (gameManager->GetFinish() == true)
    {
        AudioManager::GetInstance().PlaySE(SEName::GAMEEND);
        sceneName = SceneName::GAME_RESULT;

    }

    return sceneName;
}

void SceneMain::Draw() 
{
    // �`��
    gameManager->Draw();
}