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
    // “ü—ÍXV
    input->Proc();

    // “ü—Í@ˆ—
    select->Proc(input);

}

int SceneResult::CheckChangeScene()
{
    return select->CheckChengButton(input->CheckDownButton(0, Button::B));
}

void SceneResult::Draw()
{
    // DrawGraph(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4, _titleLogoHandle, true);
    SetFontSize(WINDOW_HEIGHT / 7);

    DrawFormatString(WINDOW_WIDTH / 2 - (WINDOW_WIDTH / 10), WINDOW_HEIGHT / 4, GetColor(255, 255, 255), "%s", "1P Win");
    // •`‰æ
    select->Draw();
}