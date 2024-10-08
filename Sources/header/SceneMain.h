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


    void Init();       // ������

    void Proc();       // ����

    void Draw();       // �`��

    int CheckChangeScene();
};

