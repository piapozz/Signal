#include "../header/StageManager.h"
#include "../header/Box.h"

StageManager::StageManager()
{
	_stageWidth = sizeof(_stageLayout) / sizeof(_stageLayout[0]);
	_stageHeight = sizeof(_stageLayout) / sizeof(_stageLayout[1]);

	_defaultStagePos.x = WINDOW_WIDTH / 2 - _stageWidth / 2 * BOX_SIZE;
	_defaultStagePos.y = WINDOW_HEIGHT * STAGE_MARGIN_RATE;

	for (int x = 0; x < sizeof(_stageLayout) / sizeof(_stageLayout[0]); x++)
	{
		for (int y = 0; y < sizeof(_stageLayout) / sizeof(_stageLayout[1]); y++)
		{
			switch ((ObjectType)_stageLayout[x][y])
			{
			case ObjectType::BOX:
				_boxList.push_back(new Box(ConvertNumToPos(x, y), BOX_LIFE));
				break;
			case ObjectType::WALL:
				_boxList.push_back(new Box(ConvertNumToPos(x, y)));
				break;
			case ObjectType::PLAYER:
			case ObjectType::ENEMY:
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

void StageManager::Proc()
{
	for (int i = 0; i < _boxList.size(); i++)
	{
		if (_boxList[i]->GetActive() == false)
			if (_boxList[i]->GetRevivalCount() > 0)
				_boxList[i]->RevivalCount();
			else
				_boxList[i]->RevivalBox();
		else if(_boxList[i]->GetStatus().m_life <= 0)
			_boxList[i]->DestroyBox();
	}
}

void StageManager::Draw()
{
	for (int i = 0; i < _boxList.size(); i++)
	{
		if (_boxList[i]->GetActive() == true)
			_boxList[i]->Draw();
	}
}

Vector2 StageManager::ConvertNumToPos(int x, int y)
{
	return _defaultStagePos + Vector2(x * BOX_SIZE, y * BOX_SIZE);
}
