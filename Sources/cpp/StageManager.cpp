#include "../header/StageManager.h"
#include "../header/Box.h"

StageManager::StageManager()
{
	_stageWidth = sizeof(_stageLayout) / sizeof(_stageLayout[1]);
	_stageHeight = sizeof(_stageLayout) / sizeof(_stageLayout[0]);

	_boxHandle = LoadGraph("Resources/Box.png");
	_wallHandle = LoadGraph("Resources/Wall.png");

	for (int x = 0; x < sizeof(_stageLayout) / sizeof(_stageLayout[1]); x++)
	{
		for (int y = 0; y < sizeof(_stageLayout) / sizeof(_stageLayout[0]); y++)
		{
			switch ((ObjectType)_stageLayout[y][x])
			{
			case ObjectType::BOX:
				_boxList.push_back(new Box(ConvertNumToPos(x, y), BOX_LIFE, _boxHandle));
				break;
			case ObjectType::WALL:
				_boxList.push_back(new Box(ConvertNumToPos(x, y), _wallHandle));
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

	SetDrawRatio();
}

StageManager::~StageManager()
{
	for (int i = 0; i < _boxList.size(); i++)
	{
		delete _boxList[i];
	}

	DeleteGraph(_boxHandle);
	DeleteGraph(_wallHandle);
}

void StageManager::SetDrawRatio()
{
	// ステージ比率と画面比率を比べて合わせる軸を決める
	float stageRatio = (float)(_stageWidth / _stageHeight);
	float windowRatio = (float)WINDOW_WIDTH / WINDOW_HEIGHT;

	if (stageRatio >= windowRatio)
	{
		_defaultStagePos.x = 0;
		_defaultStagePos.y = 0;
		//drawRatio = (float)_stageWidth / (float)(WINDOW_WIDTH + WINDOW_WIDTH * STAGE_MARGIN_RATE);
	}
	else
	{
		_defaultStagePos.x = 0;
		_defaultStagePos.y = 0;
		//drawRatio = (float)_stageHeight / (float)(WINDOW_HEIGHT + WINDOW_HEIGHT * STAGE_MARGIN_RATE);
	}
}

void StageManager::Proc()
{
	for (int i = 0; i < _boxList.size(); i++)
	{
		// boxが非アクティブなら復活をカウント
		if (_boxList[i]->GetActive() == false)
			if (_boxList[i]->GetRevivalCount() > 0)
				_boxList[i]->RevivalCount();
			else
				_boxList[i]->RevivalBox();
		// 体力がなくなったら非アクティブにする
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

Box* StageManager::GetNearBox(Vector2 pos)
{
	Box* nearBox = _boxList[0];
	float nearDistance = Vector2::Distance(pos, nearBox->GetStatus().m_position);
	for (int i = 1; i < _boxList.size(); i++)
	{
		// 非アクティブならスキップ
		if (_boxList[i]->GetStatus().m_isActive == false) continue;
		// 壁ならスキップ
		if (_boxList[i]->GetIsWall() == true) continue;

		// 距離の比較
		float distance = Vector2::Distance(pos, _boxList[i]->GetStatus().m_position);
		if (distance < nearDistance)
			nearBox = _boxList[i];
	}

	return nearBox;
}