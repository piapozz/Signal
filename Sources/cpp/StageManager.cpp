#include "../header/StageManager.h"
#include "../header/Box.h"

StageManager::StageManager()
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			switch ((ObjectType)_stageLayout[x][y])
			{
			case ObjectType::BOX:
				_boxList.push_back(new Box(ConvertNumToPos(x, y), 1.0f));
				break;
			case ObjectType::WALL:
				_boxList.push_back(new Box(ConvertNumToPos(x, y)));
				break;
			default:
				continue;
				break;
			}
		}
	}
}

StageManager::~StageManager()
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			delete _stageData[x][y];
		}
	}
}

Vector2 StageManager::ConvertNumToPos(int x, int y)
{
	return Vector2(x * BOX_SIZE, y * BOX_SIZE);
}

std::vector<Box> StageManager::GetBoxData()
{
	return _boxList;
}