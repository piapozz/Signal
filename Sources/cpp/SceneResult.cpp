#include "../header/SceneResult.h"

SceneResult::SceneResult()
{
    select = new SelectionButton();
}

SceneResult::~SceneResult()
{
    delete(select);
}

void SceneResult::Init()
{
    select->SetSelectNum(RESULT_SELECT_NUMBER);
    select->Init(str);
}

void SceneResult::Proc()
{
    // 入力更新
    input->Proc();

    // 入力　処理
    select->Proc(input);

}

int SceneResult::CheckChangeScene()
{
    return select->CheckChangeButton(input->CheckDownButton(0, Button::B));
}

void SceneResult::Draw()
{
    // DrawGraph(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4, _titleLogoHandle, true);
    SetFontSize(WINDOW_HEIGHT / 7);

    DrawFormatString(WINDOW_WIDTH / 2 - (WINDOW_WIDTH / 10), WINDOW_HEIGHT / 4, GetColor(255, 255, 255), "%dP WIN!!", Memory::GetInstance().winner);
    // 描画
    select->Draw();
}