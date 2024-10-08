#pragma once
#include "BaseScene.h"
#include "GameManager.h"

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

