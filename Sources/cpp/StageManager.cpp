#include "../header/StageManager.h"

StageManager::StageManager(CollisionManager* collisionManager)
{
	_pCollisionManager = collisionManager;

	_stageWidth = sizeof(_stageLayout) / sizeof(_stageLayout[1]);
	_stageHeight = sizeof(_stageLayout) / sizeof(_stageLayout[0]);

	_boxHandle = LoadGraph(BOX_GRAPH_ADRESS.c_str());
	_wallHandle = LoadGraph(WALL_GRAPH_ADRESS.c_str());

	SetDrawRatio();

	int boxCount = 0;
	for (int x = 0; x < sizeof(_stageLayout) / sizeof(_stageLayout[1]); x++)
	{
		for (int y = 0; y < sizeof(_stageLayout) / sizeof(_stageLayout[0]); y++)
		{
			switch ((ObjectType)_stageLayout[y][x])
			{
			case ObjectType::BOX:
				_boxList.push_back(new Box(ConvertNumToPos(x, y), BOX_LIFE, REVIVAL_TIME, _boxHandle));
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
		Box* box = _boxList[i];
		// box����A�N�e�B�u�Ȃ畜�����J�E���g
		if (box->GetActive() == false)
		{
			// �J�E���g�ɒB���Ă��Ȃ��Ȃ�J�E���g
			if (box->GetRevivalCount() > 0)
				box->RevivalCount();
			// �J�E���g�ɒB���Ă��āA���̏�ɉ����Ȃ��Ȃ畜��
			else if (!_pCollisionManager->HitCheckBox_Other(box))
				box->RevivalBox();
		}
	}
}

void StageManager::Draw()
{
	for (int i = 0; i < _boxList.size(); i++)
	{
		Box* box = _boxList[i];
		if (box->GetActive() == true)
			box->Draw();
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
		Box* box = _boxList[i];
		// ��A�N�e�B�u�Ȃ�X�L�b�v
		if (box->GetStatus().m_isActive == false) continue;
		// �ǂȂ�X�L�b�v
		if (box->GetIsWall() == true) continue;

		// �����̔�r
		float distance = Vector2::Distance(pos, box->GetStatus().m_position);
		if (distance < nearDistance)
			nearBox = box;
	}

	return nearBox;
}