#include "../header/SelectionButton.h"

SelectionButton::SelectionButton() 
{
}

SelectionButton::~SelectionButton()
{

}

void SelectionButton::SetSelectNum(int num)
{
	_selectCount = num;
}

void SelectionButton::Init(std::vector<std::string> str)
{
	// 配列を選択文字列にコピーする
	for (int i = 0; i < str.size(); i++)
	{
		_selectString.push_back(str[i]);
	}
}

void SelectionButton::Proc(InputManager* input)
{
	if (input->GetStick(0, Stick::LEFT).y < -0.7 )
	{
		_nowSelecteNumber -= 1;
		_luminance = 0;
		
	}

	if (input->GetStick(0, Stick::LEFT).y > 0.7)
	{
		_nowSelecteNumber += 1;
		_luminance = 0;
		
	}

	if(_nowSelecteNumber >= _selectCount)
	{
		_nowSelecteNumber = 0;
	}
	if (_nowSelecteNumber < 0)
	{
		_nowSelecteNumber = _selectCount - 1;
	}
	
}

BaseScene::SceneName SelectionButton::CheckChengButton(bool input)
{
	if (input)
	{
		if (_selectString[_nowSelecteNumber] == "New Game") return BaseScene::SceneName::GAME_MAIN;
		if (_selectString[_nowSelecteNumber] == "Option") return BaseScene::SceneName::GAME_OPTION;
		if (_selectString[_nowSelecteNumber] == "Exit") return BaseScene::SceneName::GAME_EXIT;
		if (_selectString[_nowSelecteNumber] == "ReTry") return BaseScene::SceneName::GAME_MAIN;
		if (_selectString[_nowSelecteNumber] == "Title") return BaseScene::SceneName::GAME_TITLE;

		return BaseScene::SceneName::NONE;
	}
	else
	{
		return BaseScene::SceneName::NONE;
	}
}

void SelectionButton::Draw()
{
	_luminance += _luminanceValue;

	if (_luminance > 255 || _luminance < 0)
	{
		_luminanceValue = -_luminanceValue;
		_luminance += _luminanceValue;
	}


	for(int i = 0; i < _selectCount;i++)
	{
		int Pos = (WINDOW_HEIGHT / 2) + ((i + 1) * ((WINDOW_HEIGHT / 2) / (_selectCount + 1)));

		int color = GetColor(255, 255, 255);
		if (i == _nowSelecteNumber) color = GetColor(_luminance, _luminance, _luminance);

		SetFontSize(WINDOW_HEIGHT / (_selectCount * 7));
		DrawFormatString((WINDOW_WIDTH / 2) - ((_selectString[i].size() / 2) * 20), Pos, color, "%s", _selectString[i].c_str());
	}
}