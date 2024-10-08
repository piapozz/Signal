#pragma once

// �V�[���̊�{�N���X
class BaseScene 
{

public:
	// �V�[���̖��O
	enum SceneName
	{
		NONE = 0,
		TITLE,
		MAIN,
		RESULT,
		OPTION,
		EXIT,

		MAX
	};


	BaseScene();
	virtual ~BaseScene();

	// ������
	virtual void Init() = 0;

	// �����Ɋ֘A������e���L�q����
	virtual void Proc() = 0;

	// �`��Ɋ֘A������e���L�q����
	virtual void Draw() = 0;

	// �V�[���̐؂�ւ�
	virtual int CheckChangeScene() = 0;
};
