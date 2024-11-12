#include "../header/CollisionManager.h"

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{

}

// �I�u�W�F�N�g���m���ߋ����ɂ��邩��Ԃ��֐�
bool CollisionManager::IsInProximity(BaseObject* obj1, BaseObject* obj2)
{
	float distance = Vector2::Distance(obj1->GetStatus().m_nextPosition, obj2->GetStatus().m_nextPosition);
	if (distance <= obj1->GetStatus().m_shapeSize / 2 + obj2->GetStatus().m_shapeSize / 2 + 50)
		return true;
	else
		return false;
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
	if (Vector2::Distance(pos1, pos2) <= (radius1 + radius2))
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
	if ((objPos.x < vertexPos[2].x + radius) && (objPos.x > vertexPos[0].x - radius) && (objPos.y > vertexPos[2].y - radius) && (objPos.y < vertexPos[0].y + radius))
		return true;
	// ��`��x�̈攻��
	if ((objPos.x > vertexPos[2].x - radius) && (objPos.x < vertexPos[0].x + radius) && (objPos.y > vertexPos[2].y - radius) && (objPos.y < vertexPos[0].y + radius))
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
			// �ڐG���Ă�����false
			if (CheckLineCross(pos1, pos2, boxList[i]->GetVertexPos(j), boxList[i]->GetVertexPos((j + 1) % 4)) == true)
				return false;
		}
	}
	// �ǂ̔��Ƃ��ڐG���Ă��Ȃ��Ȃ�true
	return true;
}

// �����Ɛ�����������Ă��邩�𔻒肷��֐�
bool CollisionManager::CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2)
{
	// �O�ς��g���Čv�Z


	return false;
}

// �v���C���[�ƓG�𔻒肷��֐�
void CollisionManager::HitCheck_Player_Player(BaseCharacter* player_1, BaseCharacter* player_2)
{
	if (HitCheck_BaseObj(player_1, player_2) == true)
	{
		// �I�u�W�F�N�g��hitFlag�𗧂Ă�
		player_1->SetHitFlag(true);
		player_2->SetHitFlag(true);
	}
}

// �v���C���[�ƒe�𔻒肷��֐�
void CollisionManager::HitCheck_Player_Bullet(BaseCharacter* player , MainBullet *bullet)
{		
	// �������Ă���
	if (HitCheck_BaseObj(player, bullet) == true)
	{
		// �܂��_���[�W��^���Ă��Ȃ��Ȃ�
		// �_���[�W����
		player->TakeDamage(bullet->GetDamage());
		// ���e����
		bullet->Impact();
		// �ђʒe�Ȃ瓖�������I�u�W�F�N�g��n��
		if (bullet->GetBulletType(BulletType::PENETRATION) > 0)
		{
			bullet->AddHitObject(player);
		}
	}
}

// �v���C���[�Ɣ��𔻒肷��֐�
void CollisionManager::HitCheck_Player_Box(BaseCharacter* player, Box* box)
{
	if (HitCheck_BaseObj_Box(player, box) == true)
	{
		// �@���̍X�V
		box->GetNormDir(player->GetStatus().m_nextPosition);

		// �I�u�W�F�N�g��hitFlag�𗧂Ă�
		player->SetHitFlag(true);
	}
}

// �e�Ɣ��𔻒肷��֐�
bool CollisionManager::HitCheck_Bullet_Box(MainBullet* bullet, Box* box)
{
	if (HitCheck_BaseObj_Box(bullet, box) == true)
	{
		// �@���̍X�V
		box->GetNormDir(bullet->GetStatus().m_nextPosition);

		// ���Ȃ�
		if (box->GetIsWall() == false)
			// �܂��_���[�W��^���Ă��Ȃ��Ȃ�
			// �_���[�W�����A�|���Ă���Ȃ�
			if (box->TakeDamage(bullet->GetDamage()) == true)
				return true;
			else
				return false;
		// ���e����
		bullet->Impact();

		// �ђʒe�Ȃ瓖�������I�u�W�F�N�g��n��
		if (bullet->GetBulletType(BulletType::PENETRATION) > 0)
		{
			bullet->AddHitObject(box);
		}
	}
}

// ���ׂẴI�u�W�F�N�g�𔻒肷��֐�
void CollisionManager::HitCheck_Everything(std::vector<BaseCharacter*> players, std::vector<Box*> boxs, BulletManager* bullets)
{
	// �v���C���[���[�v
	for (int p1 = 0; p1 < players.size(); p1++)
	{
		BaseCharacter* player_1 = players[p1];

		// ���̃��[�v
		for (int bo = 0; bo < boxs.size(); bo++)
		{
			Box* box = boxs[bo];

			for (int p2 = 0; p2 < players.size(); p2++)
			{
				BaseCharacter* player_2 = players[p2];

				std::vector<MainBullet*> bulletList = bullets->GetBulletList()[p2].m_BulletList;
				//std::vector<MainBullet*> explosionList = bullets->GetBulletList()[p2].m_ExplosionList;

				// �e�̃��[�v
				for (int bu = 0; bu < bulletList.size(); bu++)
				{
					MainBullet* bullet = bulletList[bu];
					// �e����A�N�e�B�u�Ȃ�X�L�b�v
					if (!bullet->GetActive()) continue;

					// �������{�l�Ȃ�X�L�b�v
					if (p1 == p2) continue;

					// �v���C���[�ƒe
					if (IsInProximity(player_1, bullet) == true)
						HitCheck_Player_Bullet(player_1, bullet);

					// ���ƒe
					if (IsInProximity(bullet, box) == true)
						if (HitCheck_Bullet_Box(bullet, box))
							player_2->GainExp(box->GetExp());
				}

				/*
				// �����̃��[�v
				for (int ex = 0; ex < explosionList.size(); ex++)
				{
					MainBullet* explosion = explosionList[ex];
					// �e����A�N�e�B�u�Ȃ�X�L�b�v
					if (!explosion->GetActive()) continue;

					// �������{�l�Ȃ�X�L�b�v
					if (p1 == p2) continue;

					// �v���C���[�ƒe
					if (IsInProximity(player_1, explosion) == true)
						HitCheck_Player_Bullet(player_1, explosion);

					// ���ƒe
					if (IsInProximity(explosion, box) == true)
						HitCheck_Bullet_Box(explosion, box);
				}
				*/
			}

			// �v���C���[�Ɣ�
			if (IsInProximity(player_1, box) == true)
			{
				HitCheck_Player_Box(player_1, box);
			}
		}

		for (int p2 = p1 + 1; p2 < players.size(); p2++)
		{
			BaseCharacter* player_2 = players[p2];

			// �����g�ݍ��킹�̓X�L�b�v
			if (p1 >= p2) continue;

			if (IsInProximity(player_1, player_2) == true)
				// �v���C���[�ƃv���C���[
				HitCheck_Player_Player(player_1, player_2);
		}
	}
}