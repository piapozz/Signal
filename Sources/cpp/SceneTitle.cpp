#include "../header/SceneTitle.h"

SceneTitle::SceneTitle()
{
    select = new SelectionButton();
    _titleLogoHandle = LoadGraph("Resources/Signal_Logo.png");
}

SceneTitle::~SceneTitle()
{
    delete(select);
}

void SceneTitle::Init()
{
    select->SetSelectNum(TITLE_SELECT_NUMBER);
    select->Init(str);
    // 時間計測用
    startTime = GetNowCount();
}

void SceneTitle::Proc()
{
    // 入力更新
    input->Proc();

    // 入力　処理
    select->Proc(input);

}

int SceneTitle::CheckChangeScene() 
{
    return select->CheckChangeButton(input->CheckDownButton(0, Button::B));
}

void SceneTitle::Draw()
{
    SetFontSize(WINDOW_HEIGHT / 7);

    // 周期を不規則に変化させる
    float randomFrequency = baseFrequency + ((std::rand() % 100 - 50) / 100.0f) * randomFrequencyOffset;

    // 経過時間を取得
    float elapsedTime = (startTime - GetNowCount()) % 100;

    // 点滅アルゴリズム
    float noise = (std::rand() % 100 - 50) / 100.0f; // ランダムな変化
    float flicker = sinf(randomFrequency * elapsedTime) + noise;

    alpha += static_cast<int>(flicker * flickerSpeed * 255);
    if (alpha < 10) alpha = 0;   // 最小アルファ値
    if (alpha > 200) alpha = 200; // 最大アルファ値

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    //DrawFormatString(WINDOW_WIDTH / 2 - (WINDOW_WIDTH / 10), WINDOW_HEIGHT / 4, GetColor(255, 255, 255), "%s", "Signal");
   // DrawGraph(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 20, _titleLogoHandle, true);
    DrawExtendGraph(
        (WINDOW_WIDTH / 2) - (TITLE_LOGO_X /2),
        (WINDOW_HEIGHT / 3) - (TITLE_LOGO_Y / 2),
        (WINDOW_WIDTH / 2) + (TITLE_LOGO_X / 2),
        (WINDOW_HEIGHT / 3) + (TITLE_LOGO_Y / 2),
        _titleLogoHandle, true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    // 描画
    select->Draw();
}