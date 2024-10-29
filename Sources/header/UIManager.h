#pragma once
#include "../header/InputManager.h"
#include "../header/Const.h"

class UIManager
{
private:
	InputManager* inputManager;

	int deviceMax = 2;

	int deviceCount;

public:
	UIManager();
	~UIManager();

	void Proc();
	void Draw();						

};

