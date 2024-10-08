#pragma once

// シーンの基本クラス
#include "BaseScene.h"

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"

class SceneManager
{
private:

	bool _exitFlag = false;

	// シーンの情報を格納
	BaseScene* _scene;

	// 補助
	void Init();

public:

	SceneManager();
	~SceneManager();

	// mainで毎フレーム呼ばれる
	void Proc();
	void Draw();

	/// 引数で渡されたシーンに切り替える
	void ChangeScene(int scene);

	bool GetExitFlag() { return _exitFlag; };

};

