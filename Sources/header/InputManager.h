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
		// �\���{�^���������Ă��邩�̃t���O
		bool upFlag = false;
		bool leftFlag = false;
		bool downFlag = false;
		bool rightFlag = false;

		// ABXY�{�^���������Ă��邩�̃t���O
		bool xFlag = false;
		bool yFlag = false;
		bool bFlag = false;
		bool aFlag = false;

		// LR�{�^���E�g���K�[�������Ă��邩�̃t���O
		bool lbFlag = false;
		bool rbFlag = false;
		bool ltFlag = false;
		bool rtFlag = false;

		// LR�X�e�B�b�N�{�^���������Ă��邩�̃t���O
		bool lsbFlag = false;
		bool rsbFlag = false;

		// �X�e�B�b�N�̓��͏��
		int lsInputX, lsInputY;
		int rsInputX, rsInputY;
	};
	*/

	DINPUT_JOYSTATE inputParam[2];		// ���͏��̍\����

	int inputControllerNum;		// �R���g���[���[�̐ڑ���

public:
	InputManager() {}
	~InputManager() {}

	void Proc();

	void AddController();

	bool CheckDownButton(int playerNum, int button);
};