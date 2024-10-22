#pragma once
#include "BaseObject.h"

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

	// ブロックの可変長配列
	BaseObject* _stageData[5][5];

public:

	StageManager();
	~StageManager();

	Vector2 ConvertNumToPos(int x, int y);
};

