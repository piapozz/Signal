#pragma once
#include <vector>
#include "BaseObject.h"
#include "Box.h"

class StageManager
{
	enum class ObjectType
	{
		NONE = 0,
		BOX,
		WALL,
		PLAYER,
		ENEMY,

		MAX
	};

private:

	// ステージの配列
	int _stageLayout[5][5] =
	{
		2, 2, 2, 2, 2,
		2, 3, 0, 0, 2,
		2, 0, 1, 0, 2,
		2, 0, 0, 4, 2,
		2, 2, 2, 2, 2
	};

	std::vector<Box*> _boxList;				// ブロックの可変長配列

	std::vector<Vector2> _playerStartPos;	// プレイヤーの初期位置

	//Vector2 _defaultStagePos = Vector;				// ステージのアンカー座標

public:

	StageManager();
	~StageManager();

	void Draw();

	Vector2 ConvertNumToPos(int x, int y);
	std::vector<Box*> GetBoxData() { return _boxList; }
	std::vector<Vector2> GetStartPos() { return _playerStartPos; }
};
