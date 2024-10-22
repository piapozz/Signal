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

	// ブロックの可変長配列
	BaseObject* _stageData[5][5];
	std::vector<Box> _boxList;

public:

	StageManager();
	~StageManager();

	Vector2 ConvertNumToPos(int x, int y);
	std::vector<Box> GetBoxData();
};
