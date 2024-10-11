#pragma once

class InputManager
{
	enum INPUT
	{
		DOWN = 0,
		LEFT,
		RIGHT,
		UP,
		X,
		Y,
		A,
		B,
		LEFT_BUTTON,
		RIGHT_BUTTON,
		LEFT_TRIGGER,
		RIGHT_TRIGGER,
		LEFT_STICK_BUTTON,
		RIGHT_STICK_BUTTON,

		MAX
	};

private:
	/*
	struct InputParam
	{
		// 十字ボタンを押しているかのフラグ
		bool upFlag = false;
		bool leftFlag = false;
		bool downFlag = false;
		bool rightFlag = false;

		// ABXYボタンを押しているかのフラグ
		bool xFlag = false;
		bool yFlag = false;
		bool bFlag = false;
		bool aFlag = false;

		// LRボタン・トリガーを押しているかのフラグ
		bool lbFlag = false;
		bool rbFlag = false;
		bool ltFlag = false;
		bool rtFlag = false;

		// LRスティックボタンを押しているかのフラグ
		bool lsbFlag = false;
		bool rsbFlag = false;

		// スティックの入力情報
		int lsInputX, lsInputY;
		int rsInputX, rsInputY;
	};
	*/

	DINPUT_JOYSTATE inputParam[2];		// 入力情報の構造体

	int inputControllerNum;		// コントローラーの接続数

public:
	InputManager() {}
	~InputManager() {}

	void Proc();

	void AddController();

	bool CheckDownButton(int playerNum, int button);
};