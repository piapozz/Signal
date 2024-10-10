#pragma once
#include "../header/BaseScene.h"
#include "../header/GameManager.h"

class SceneMain :
    public BaseScene
{
private:

    int sceneName = BaseScene::SceneName::NONE;

    GameManager* gameManager;

public:

    SceneMain();
    ~SceneMain();


    void Init();       // ‰Šú‰»

    void Proc();       // ˆ—

    void Draw();       // •`‰æ

    int CheckChangeScene();
};

