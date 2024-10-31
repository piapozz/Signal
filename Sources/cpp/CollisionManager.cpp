#include "../header/CollisionManager.h"

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{

}

// �x�[�X�I�u�W�F�N�g�ƃx�[�X�I�u�W�F�N�g�̔���
bool CollisionManager::HitCheck_BaseObj(BaseObject* obj1, BaseObject* obj2)
{
	// ���W�Ɣ��a
	Vector2 pos1 = obj1->GetStatus().m_nextPosition;
	float radius1 = obj1->GetStatus().m_shapeSize;
	Vector2 pos2 = obj2->GetStatus().m_nextPosition;
	float radius2 = obj2->GetStatus().m_shapeSize;

	// �����̍������a�̍��v�ȉ��Ȃ�ڐG
	if (Vector2::Distance(pos1, pos2) >= (radius1 + radius2))
	{
		return true;
	}

	return false;
}

// �x�[�X�I�u�W�F�N�g�Ɣ��̔���
bool CollisionManager::HitCheck_BaseObj_Box(BaseObject* obj, Box* box)
{
	Vector2 objPos = obj->GetStatus().m_nextPosition;
	Vector2 vertexPos[4];
	float radius = obj->GetStatus().m_shapeSize;
	for (int i = 0; i < 4; i++)
	{
		vertexPos[i] = box->GetVertexPos(i);
	}

	// ��`��y�̈攻��
	if ((objPos.x > vertexPos[2].x) && (objPos.x < vertexPos[0].x) && (objPos.y > vertexPos[2].y - radius) && (objPos.y < vertexPos[0].y + radius))
		return true;
	// ��`��x�̈攻��
	if ((objPos.x > vertexPos[2].x - radius) && (objPos.x < vertexPos[0].x + radius) && (objPos.y > vertexPos[2].y) && (objPos.y < vertexPos[0].y))
		return true;
	// �e���_�̗̈攻��
	for (int i = 0; i < 4; i++)
	{
		float distanceX = vertexPos[i].x - objPos.x;
		float distanceY = vertexPos[i].y - objPos.y;

		if (powf(distanceX, 2) + powf(distanceY, 2) < powf(radius, 2))
		{
			return true;
		}
	}

	return false;
}

// �݂���
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
	return false;
}

// �v���C���[�ƓG�𔻒肷��֐�
void CollisionManager::HitCheck_Player_Player(std::vector<BaseCharacter*> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < players.size(); j++)
		{
			if (i >= j) return;

			if (HitCheck_BaseObj(players[i], players[j]))
			{
				// �I�u�W�F�N�g��hitFlag�𗧂Ă�
				players[i]->SetHitFlag(true);
				players[j]->SetHitFlag(true);
			}
		}
	}
}

// �v���C���[�ƒe�𔻒肷��֐�
void CollisionManager::HitCheck_Player_Bullet(std::vector<BaseCharacter*> players , BulletManager *bullet)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < bullet->GetBulletList().size(); j++)
		{
			if (i == j) continue;
			for (int k = 0; k < bullet->GetBulletList()[j].m_BulletList.size(); k++)
			{
				if (HitCheck_BaseObj(players[i],bullet->GetBulletList()[j].m_BulletList[k]))
				{
					// �_���[�W����
					players[i]->TakeDamage(bullet->GetBulletList()[i].m_BulletList[j]->GetPower());
				}
			}
		}
	}
}

// �v���C���[�Ɣ��𔻒肷��֐�
void CollisionManager::HitCheck_Player_Box(std::vector<BaseCharacter*> players, std::vector<Box*> boxs)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < boxs.size(); j++)
		{
			if (HitCheck_BaseObj_Box(players[i], boxs[j]))
			{
				// �I�u�W�F�N�g��hitFlag�𗧂Ă�
				players[i]->SetHitFlag(true);
				boxs[j]->SetHitFlag(true);
			}
		}
	}
}

// �e�Ɣ��𔻒肷��֐�
void CollisionManager::HitCheck_Bullet_Box(std::vector<Box*> boxs, BulletManager* bullet)
{
	for (int i = 0; i < boxs.size(); i++)
	{
		for (int j = 0; j < bullet->GetBulletList().size(); j++)
		{
			for (int k = 0; k < bullet->GetBulletList()[j].m_BulletList.size(); k++)
			{
				if (!bullet->GetBulletList()[j].m_BulletList[k]->GetActive()) continue;

				if (HitCheck_BaseObj_Box(bullet->GetBulletList()[j].m_BulletList[k], boxs[i]))
				{
					// �ǂ��ǂ����ŕ���
					if (boxs[j]->GetIsWall() == true)
						bullet->GetBulletList()[i].m_BulletList[j]->Destroy();
					else
						// �_���[�W����
						boxs[j]->TakeDamage(bullet->GetBulletList()[i].m_BulletList[j]->GetPower());
				}
			}
		}
	}
}

void CollisionManager::HitCheck_Everything(std::vector<BaseCharacter*> players, std::vector<Box*> boxs, BulletManager* bullet)
{
	HitCheck_Player_Player(players);
	HitCheck_Player_Bullet(players, bullet);
	HitCheck_Player_Box(players, boxs);
	HitCheck_Bullet_Box(boxs, bullet);
}