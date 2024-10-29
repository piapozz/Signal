#include "../header/CollisionManager.h"
#include "../header/StageManager.h"

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{

}

// �x�[�X�I�u�W�F�N�g�ƃx�[�X�I�u�W�F�N�g�̔���
bool CollisionManager::HitCheckBaseObj(BaseObject obj1, BaseObject obj2)
{
	// ���W�Ɣ��a
	Vector2 pos1 = obj1.GetStatus().m_position;
	float radius1 = obj1.GetStatus().m_shapeSize;
	Vector2 pos2 = obj2.GetStatus().m_position;
	float radius2 = obj2.GetStatus().m_shapeSize;

	// �����̍������a�̍��v�ȉ��Ȃ�ڐG
	if (Vector2::Distance(pos1, pos2) >= (radius1 + radius2))
	{
		return true;
	}

	return false;
}

// �ː����ʂ��Ă��邩���C�Ŕ��肷��֐�
bool CollisionManager::CheckBetweenObject(Vector2 pos1, Vector2 pos2, std::vector<Box*> boxList)
{
	// ���ׂĂ̔��Ɣ���
	for (int i = 0; i < boxList.size(); i++)
	{
		// ��O����
		// ��������̋������ڐG���Ȃ������Ȃ�X�L�b�v
		if (false) continue;

		// ���ׂĂ̕ӂƔ���
		for (int j = 0; j < 4; j++)
		{
			if (CheckLineCross(pos1, pos2, boxList[i]->GetVertexPos(j), boxList[i]->GetVertexPos((j + 1) % 4)) == true)
				return false;
		}
	}
	return true;
}

// �����Ɛ�����������Ă��邩�𔻒肷��֐�
bool CollisionManager::CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2)
{

}

// �v���C���[�ƓG�𔻒肷��֐�
void CollisionManager::HitCheck_Player_Player(std::vector<BaseObject> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < players.size(); j++)
		{
			if (i >= j) return;

			if (HitCheckBaseObj(players[i], players[j]))
			{
				// �I�u�W�F�N�g��hitFlag�𗧂Ă�
			}
		}
	}
}

// �v���C���[�ƒe�𔻒肷��֐�
void CollisionManager::HitCheck_Player_Bullet(std::vector<BaseObject> players, std::vector<BaseObject> bullets)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < bullets.size(); j++)
		{
			if (i >= j) return;

			if (HitCheckBaseObj(players[i], bullets[j]))
			{
				// �I�u�W�F�N�g��hitFlag�𗧂Ă�
			}
		}
	}
}

// �v���C���[�Ɣ��𔻒肷��֐�
void CollisionManager::HitCheck_Player_Box(std::vector<BaseObject> players, std::vector<Box> boxs)
{

}

// �e�Ɣ��𔻒肷��֐�
void CollisionManager::HitCheck_Bullet_Box(std::vector<BaseObject> bullets, std::vector<Box> boxs)
{

}