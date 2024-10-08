#pragma once

// シーンの基本クラス
class BaseScene 
{

public:
	// シーンの名前
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

	// 初期化
	virtual void Init() = 0;

	// 処理に関連する内容を記述する
	virtual void Proc() = 0;

	// 描画に関連する内容を記述する
	virtual void Draw() = 0;

	// シーンの切り替え
	virtual int CheckChangeScene() = 0;
};
