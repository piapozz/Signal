#include "../header/SceneTitle.h"

SceneTitle::SceneTitle()
{
    select = new SelectionButton();
    _titleLogoHandle = LoadGraph("Resources/Enemy.png");
}

SceneTitle::~SceneTitle()
{
    delete(select);
}

void SceneTitle::Init()
{
    select->SetSelectNum(TITLE_SELECT_NUMBER);
    select->Init(str);
    // ���Ԍv���p
    startTime = GetNowCount();
}

void SceneTitle::Proc()
{
    // ���͍X�V
    input->Proc();

    // ���́@����
    select->Proc(input);

}

int SceneTitle::CheckChangeScene() 
{
    return select->CheckChengButton(input->CheckDownButton(0, Button::B));
}

void SceneTitle::Draw()
{
    // DrawGraph(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4, _titleLogoHandle, true);
    SetFontSize(WINDOW_HEIGHT / 7);

    // ������s�K���ɕω�������
    float randomFrequency = baseFrequency + ((std::rand() % 100 - 50) / 100.0f) * randomFrequencyOffset;

    // �o�ߎ��Ԃ��擾
    float elapsedTime = (startTime - GetNowCount()) % 100;

    // �_�ŃA���S���Y��
    float noise = (std::rand() % 100 - 50) / 100.0f; // �����_���ȕω�
    float flicker = sinf(randomFrequency * elapsedTime) + noise;

    alpha += static_cast<int>(flicker * flickerSpeed * 255);
    if (alpha < 10) alpha = 0;   // �ŏ��A���t�@�l
    if (alpha > 200) alpha = 200; // �ő�A���t�@�l

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawFormatString(WINDOW_WIDTH / 2 - (WINDOW_WIDTH / 10), WINDOW_HEIGHT / 4, GetColor(255, 255, 255), "%s", "Signal");
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    // �`��
    select->Draw();
}