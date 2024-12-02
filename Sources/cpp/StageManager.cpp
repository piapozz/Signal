#include "../header/StageManager.h"
#include "../header/Box.h"

StageManager::StageManager()
{
	_stageWidth = sizeof(_stageLayout) / sizeof(_stageLayout[1]);
	_stageHeight = sizeof(_stageLayout) / sizeof(_stageLayout[0]);

	_boxHandle = LoadGraph("Resources/Box.png");
	_wallHandle = LoadGraph("Resources/Wall.png");

	SetDrawRatio();

	int boxCount = 0;
	for (int x = 0; x < sizeof(_stageLayout) / sizeof(_stageLayout[1]); x++)
	{
		for (int y = 0; y < sizeof(_stageLayout) / sizeof(_stageLayout[0]); y++)
		{
			switch ((ObjectType)_stageLayout[y][x])
			{
			case ObjectType::BOX:
				_boxList.push_back(new Box(ConvertNumToPos(x, y), BOX_LIFE, _boxHandle));
				boxCount++;
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

	_boxRevivalTime = REVIVAL_TIME * boxCount;
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
	// �X�e�[�W�䗦�Ɖ�ʔ䗦���ׂč��킹�鎲�����߂�
	float stageRatio = (float)(_stageWidth / _stageHeight);
	float windowRatio = (float)WINDOW_WIDTH / WINDOW_HEIGHT;

	if (stageRatio >= windowRatio)
	{
		_boxSize = (float)(WINDOW_WIDTH - (float)(WINDOW_WIDTH * STAGE_MARGIN_RATE * 2)) / ((float)_stageWidth);
		drawRatio = _boxSize / BOX_SIZE;
		drawAnchorPos.x = (WINDOW_HEIGHT - (float)_stageHeight * _boxSize + _boxSize) / 2;
		drawAnchorPos.y = WINDOW_WIDTH * STAGE_MARGIN_RATE;
	}
	else
	{
		// ��ʂ̍�������]�����������������u���b�N1���Ɋ���
		_boxSize = (float)(WINDOW_HEIGHT - (float)(WINDOW_HEIGHT * STAGE_MARGIN_RATE * 2)) / ((float)_stageHeight);
		drawRatio = _boxSize / BOX_SIZE;
		drawAnchorPos.x = (WINDOW_WIDTH - (float)_stageWidth * _boxSize + _boxSize) / 2;
		drawAnchorPos.y = WINDOW_HEIGHT * STAGE_MARGIN_RATE;
	}
}

void StageManager::Proc()
{
	for (int i = 0; i < _boxList.size(); i++)
	{
		// box����A�N�e�B�u�Ȃ畜�����J�E���g
		if (_boxList[i]->GetActive() == false)
			if (_boxList[i]->GetRevivalCount() > 0)
				_boxList[i]->RevivalCount();
			else
				_boxList[i]->RevivalBox();
		// �̗͂��Ȃ��Ȃ������A�N�e�B�u�ɂ���
		else if(_boxList[i]->GetStatus().m_life <= 0)
			_boxList[i]->DestroyBox(_boxRevivalTime);
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
	Vector2 result = Vector2(x, y) * BOX_SIZE;
	return result;
}

Box* StageManager::GetNearBox(Vector2 pos)
{
	Box* nearBox = _boxList[0];
	float nearDistance = Vector2::Distance(pos, nearBox->GetStatus().m_position);
	for (int i = 1; i < _boxList.size(); i++)
	{
		// ��A�N�e�B�u�Ȃ�X�L�b�v
		if (_boxList[i]->GetStatus().m_isActive == false) continue;
		// �ǂȂ�X�L�b�v
		if (_boxList[i]->GetIsWall() == true) continue;

		// �����̔�r
		float distance = Vector2::Distance(pos, _boxList[i]->GetStatus().m_position);
		if (distance < nearDistance)
			nearBox = _boxList[i];
	}

	return nearBox;
}