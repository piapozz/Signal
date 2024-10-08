#pragma once
#include "BaseScene.h"

class SceneTitle :
    public BaseScene
{

private:

    int sceneName = BaseScene::SceneName::NONE;

public:

    SceneTitle();
    ~SceneTitle();

    void Init();
    void Proc();
    void Draw();
    int CheckChangeScene();
};

