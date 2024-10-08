#pragma once
#include "BaseScene.h"

class SceneResult :
    public BaseScene 
{
private:

    int sceneName = BaseScene::SceneName::NONE;

public:

    SceneResult();
    ~SceneResult();

    void Init();
    void Proc();
    void Draw();
    int CheckChangeScene();
};