#pragma once
#include "../header/BaseCharacter.h"

class Player : public BaseCharacter
{
private:
	BulletManager* bulletManager;
	InputManager* inputManager;

public:
	// �R���g���[���[�̏�Ԃ��Ǘ�����
	struct Controller
	{
		Vector2 m_RStick;
		Vector2 m_LStick;
		bool m_LTrigger;
		bool m_RTrigger;
	};

	Controller controller;

	Player(Vector2 pos);					// �R���X�g���N�^
	~Player();								// �f�X�g���N�^

	void Proc();
	void Init(BulletManager* bullet, InputManager* input);
	void GetController();
	int InputButtonToInt();
};