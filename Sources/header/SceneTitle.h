#pragma once
#include "BaseScene.h"
#include "SelectionButton.h"

class SceneTitle :
    public BaseScene
{
private:

    int _titleLogoHandle = LoadGraph("Resources/Signal_Logo");

    SelectionButton* select;

    const int TITLE_SELECT_NUMBER = 3;

    float alpha = 255;                  // �A���t�@�l
    float flickerSpeed = 0.05f;          // �_�ł̕ω����x
    float baseFrequency = 5.0f;         // ��{�̓_�Ŏ���
    float randomFrequencyOffset = 1.0f; // �����̃����_���Ȕ͈�

    int startTime;

    vector<string> str = {
       "New Game",
       "Optipn",
       "Exit",
    };

public:

    SceneTitle();
    ~SceneTitle();

    void Init();
    void Proc();
    void Draw();
    int CheckChangeScene();
};

