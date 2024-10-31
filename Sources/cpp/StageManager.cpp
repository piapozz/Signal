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
			case (ObjectType::PLAYER, ObjectType::ENEMY):
				_playerStartPos.push_back(ConvertNumToPos(x, y));
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
	for (int i = 0; i < _boxList.size(); i++)
	{
		delete _boxList[i];
	}
}

void StageManager::Draw()
{
	for (int i = 0; i < _boxList.size(); i++)
	{
		_boxList[i]->Draw();
	}
}

Vector2 StageManager::ConvertNumToPos(int x, int y)
{
	return Vector2(x * BOX_SIZE, y * BOX_SIZE);
}
