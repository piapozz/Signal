#pragma once
#include "BaseScene.h"
#include "SelectionButton.h"
#include "Memory.h"

class SceneResult :
    public BaseScene
{
private:

    int _resultLogoHandle;

    SelectionButton* select;

    const int RESULT_SELECT_NUMBER = 3;

    vector<string> str = {
        "Title",
        "Retry",
        "Optipn",
        "Exit",
    };

public:

    SceneResult();
    ~SceneResult();

    void Init();
    void Proc();
    void Draw();
    int CheckChangeScene();
};

