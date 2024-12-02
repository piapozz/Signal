#pragma once
#include "InputManager.h"
#include "BaseScene.h"

class SelectionButton
{
private:

	int _selectCount = 1; 
	int _nowSelecteNumber = 0;

	int _luminance = 0;
	int _luminanceValue= 3;

	float fontSize = 7.0f;

	std::vector<std::string> _selectString;

public:

	SelectionButton();
	~SelectionButton();

	void SetSelectNum(int num);

	void Init(std::vector<std::string> str);

	BaseScene::SceneName CheckChangeButton(bool input);

	void Proc(InputManager* input);

	void Draw();
};

