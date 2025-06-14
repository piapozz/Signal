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


    void Init();       // 初期化

    void Proc();       // 処理

    void Draw();       // 描画

    int CheckChangeScene();
};

