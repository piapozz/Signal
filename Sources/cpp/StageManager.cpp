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
			case ObjectType::NONE:
				continue;
				break;
			case ObjectType::BOX:
				_stageData[x][y] = new Box(ConvertNumToPos(x, y));
				break;
			}
		}
	}
}

Vector2 StageManager::ConvertNumToPos(int x, int y)
{
	return Vector2(x * BOX_SIZE, y * BOX_SIZE);
}