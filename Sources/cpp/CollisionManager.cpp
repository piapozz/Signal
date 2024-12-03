#include "../header/CollisionManager.h"

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::Init(vector<BaseCharacter*> players, vector<Box*> boxs, BulletManager* bullet)
{
	_pPlayers = players;
	_pBoxs = boxs;
	_pBullet = bullet;
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

// �ː����ʂ��Ă��邩���C�Ŕ��肷��֐�
bool CollisionManager::CheckHitRay(Vector2 pos1, Vector2 pos2)
{
	// ���ׂĂ̔��Ɣ���
	for (int i = 0; i < _pBoxs.size(); i++)
	{
		// ��O����
		// ��������̋������ڐG���Ȃ������Ȃ�X�L�b�v
		//if (false) continue;

		// ���ׂĂ̕ӂƔ���
		for (int j = 0; j < 4; j++)
		{
			// �ڐG���Ă�����false
			if (CheckLineCross(pos1, pos2, _pBoxs[i]->GetVertexPos(j), _pBoxs[i]->GetVertexPos((j + 1) % 4)) == true)
				return false;
		}
	}
	// �ǂ̔��Ƃ��ڐG���Ă��Ȃ��Ȃ�true
	return true;
}

// �����Ɛ�����������Ă��邩�𔻒肷��֐�
bool CollisionManager::CheckLineCross(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
	// �O�ς��g���Čv�Z
	// �O���[�v�@
	Vector2 a_to_b = b - a;
	Vector2 a_to_c = c - a;
	Vector2 a_to_d = d - a;

	float cross1 = Vector2::Cross(a_to_b, a_to_c);
	float cross2 = Vector2::Cross(a_to_b, a_to_d);

	if (cross1 * cross2 > 0)
		return false;

	// �O���[�v�A
	Vector2 c_to_d = d - c;
	Vector2 c_to_a = a - c;
	Vector2 c_to_b = b - c;

	cross1 = Vector2::Cross(c_to_d, c_to_a);
	cross2 = Vector2::Cross(c_to_d, c_to_b);

	if (cross1 * cross2 > 0)
		return false;

	return true;
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
		std::vector<BaseObject*> hitCharaList = bullet->hitCharObject;
		// ���łɓ������Ă���I�u�W�F�N�g�Ȃ�X�L�b�v
		for (int i = 0; i < hitCharaList.size(); i++)
		{
			if (player == hitCharaList[i])
			{
				return;
			}
		}

		// �_���[�W����
		player->TakeDamage(bullet->GetDamage());
		// ���ʉ�
		AudioManager::GetInstance().PlaySE(SEName::DAMAGE);
		// ���������I�u�W�F�N�g��n��
		bullet->hitCharObject.push_back(player);
		// ���e����
		bullet->Impact(ObjectType::PLAYER);
	}
}

// �v���C���[�Ɣ����𔻒肷��֐�
void CollisionManager::HitCheck_Player_Explosion(BaseCharacter* player, Explosion* explosion)
{
	// �������Ă���
	if (HitCheck_BaseObj(player, explosion) == true)
	{
		std::vector<BaseObject*> hitCharaList = explosion->hitCharObject;
		// ���łɓ������Ă���I�u�W�F�N�g�Ȃ�X�L�b�v���A
		// �������Ă���I�u�W�F�N�g���X�V
		for (int i = 0; i < hitCharaList.size(); i++)
		{
			if (player == hitCharaList[i])
			{
				return;
			}
		}

		// �_���[�W����
		player->TakeDamage(explosion->GetDamage());
		// ���������I�u�W�F�N�g��n��
		explosion->hitCharObject.push_back(player);
	}
}

// �v���C���[�Ɣ��𔻒肷��֐�
void CollisionManager::HitCheck_Player_Box(BaseCharacter* player, Box* box)
{
	if (HitCheck_BaseObj_Box(player, box) == true)
	{
		// �I�u�W�F�N�g��hitFlag�𗧂Ă�
		player->SetHitFlag(true);
	}
}

// �e�Ɣ��𔻒肷��֐�
bool CollisionManager::HitCheck_Bullet_Box(MainBullet* bullet, Box* box)
{
	bool result = false;

	if (HitCheck_BaseObj_Box(bullet, box) == true)
	{
		// �_���[�W��^���Ă���Ȃ�X�L�b�v
		std::vector<Box*> hitBoxList = bullet->hitBoxObject;
		bool isHit = false;
		for (int i = 0; i < hitBoxList.size(); i++)
		{
			if (box == hitBoxList[i])
				return result;
		}

		ObjectType objType = ObjectType::WALL;

		// ���Ȃ�
		if (box->GetIsWall() == false)
		{
			objType = ObjectType::BOX;

			// �_���[�W�����A�|���Ă���Ȃ�
			if (box->TakeDamage(bullet->GetDamage()) == true)
				result = true;
		}

		// ���������I�u�W�F�N�g��n��
		bullet->hitBoxObject.push_back(box);

		AudioManager::GetInstance().PlaySE(SEName::IMPACT);

		// ���e����
		bullet->Impact(objType);
	}

	return result;
}

// �����Ɣ��𔻒肷��֐�
bool CollisionManager::HitCheck_Explosion_Box(Explosion* explosion, Box* box)
{
	bool result = false;

	if (HitCheck_BaseObj_Box(explosion, box) == true)
	{
		// �_���[�W��^���Ă���Ȃ�X�L�b�v
		std::vector<Box*> hitBoxList = explosion->hitBoxObject;
		bool isHit = false;
		for (int i = 0; i < hitBoxList.size(); i++)
		{
			if (box == hitBoxList[i])
				return result;
		}

		ObjectType objType = ObjectType::WALL;

		// ���Ȃ�
		if (box->GetIsWall() == false)
		{
			objType = ObjectType::BOX;

			// �_���[�W�����A�|���Ă���Ȃ�
			if (box->TakeDamage(explosion->GetDamage()) == true)
				result = true;
		}

		// ���������I�u�W�F�N�g��n��
		explosion->hitBoxObject.push_back(box);
	}

	return result;
}

// ���ׂẴI�u�W�F�N�g�𔻒肷��֐�
void CollisionManager::HitCheck_Everything()
{
	// �v���C���[�̓����蔻��
	for (int p1 = 0; p1 < _pPlayers.size(); p1++)
	{
		BaseCharacter* player_1 = _pPlayers[p1];

		// �v���C���[���Ƃ̔���
		for (int p2 = 0; p2 < _pPlayers.size(); p2++)
		{
			// �����g�ݍ��킹�̓X�L�b�v
			if (p1 == p2) continue;
			BaseCharacter* player_2 = _pPlayers[p2];

			// �ق��v���C���[�Ƃ̓����蔻��
			if (IsInProximity(player_1, player_2) == true)
				// �v���C���[�ƃv���C���[
				HitCheck_Player_Player(player_1, player_2);

			// �e�Ƃ̔���
			std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p2].m_BulletList;
			std::vector<Explosion*> explosionList = _pBullet->GetBulletList()[p2].m_ExplosionList;

			// �e�̃��[�v
			for (int bu = 0; bu < bulletList.size(); bu++)
			{
				MainBullet* bullet = bulletList[bu];
				// �e����A�N�e�B�u�Ȃ�X�L�b�v
				if (!bullet->GetActive()) continue;

				// �v���C���[�ƒe
				if (IsInProximity(player_1, bullet) == true)
					HitCheck_Player_Bullet(player_1, bullet);
			}

			// �����̃��[�v
			for (int ex = 0; ex < explosionList.size(); ex++)
			{
				Explosion* explosion = explosionList[ex];
				// ��������A�N�e�B�u�Ȃ�X�L�b�v
				if (!explosion->GetActive()) continue;

				// �v���C���[�Ɣ���
				if (IsInProximity(player_1, explosion) == true)
					HitCheck_Player_Explosion(player_1, explosion);
			}
		}

		// box�Ƃ̔���
		for (int bo = 0; bo < _pBoxs.size(); bo++)
		{
			Box* box = _pBoxs[bo];
			// ������A�N�e�B�u�Ȃ�X�L�b�v
			if (!box->GetActive()) continue;

			
			if (IsInProximity(player_1, box) == true)
			{
				HitCheck_Player_Box(player_1, box);
			}
		}
	}

	// box�ƒe�̔���
	for (int bo = 0; bo < _pBoxs.size(); bo++)
	{
		Box* box = _pBoxs[bo];
		// ������A�N�e�B�u�Ȃ�X�L�b�v
		if (!box->GetActive()) continue;

		// �v���C���[�̐��J��Ԃ�
		for (int p2 = 0; p2 < _pPlayers.size(); p2++)
		{
			BaseCharacter* player_2 = _pPlayers[p2];

			std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p2].m_BulletList;
			std::vector<Explosion*> explosionList = _pBullet->GetBulletList()[p2].m_ExplosionList;

			// �e�̃��[�v
			for (int bu = 0; bu < bulletList.size(); bu++)
			{
				MainBullet* bullet = bulletList[bu];
				// �e����A�N�e�B�u�Ȃ�X�L�b�v
				if (!bullet->GetActive()) continue;

				if (IsInProximity(bullet, box) == true)
					if (HitCheck_Bullet_Box(bullet, box))
						player_2->GainExp(box->GetExp());
			}

			// �����̃��[�v
			for (int ex = 0; ex < explosionList.size(); ex++)
			{
				Explosion* explosion = explosionList[ex];
				// ��������A�N�e�B�u�Ȃ�X�L�b�v
				if (!explosion->GetActive()) continue;

				if (IsInProximity(explosion, box) == true)
					if (HitCheck_Explosion_Box(explosion, box))
						player_2->GainExp(box->GetExp());
			}
		}
	}
}

// �e�����������I�u�W�F�N�g���X�V����
void CollisionManager::UpdateHitObj()
{
	// �v���C���[���Ƃ̔���
	for (int p2 = 0; p2 < _pPlayers.size(); p2++)
	{
		std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p2].m_BulletList;
		// �e�̃��[�v
		for (int bu = 0; bu < bulletList.size(); bu++)
		{
			// �v���C���[�Ƃ̔���
			std::vector<BaseObject*>& hitCharaList = bulletList[bu]->hitCharObject;
			for (int chara = hitCharaList.size() - 1; chara >= 0; chara--)
			{
				// �v���C���[���ڐG���Ă��Ȃ��Ȃ烊�X�g����폜
				if (!HitCheck_BaseObj(bulletList[bu], hitCharaList[chara]))
					hitCharaList.erase(hitCharaList.begin() + chara);
			}

			// box�Ƃ̔���
			std::vector<Box*>& hitBoxList = bulletList[bu]->hitBoxObject;
			for (int box = hitBoxList.size() - 1; box >= 0; box--)
			{
				// �v���C���[���ڐG���Ă��Ȃ��Ȃ烊�X�g����폜
				if (!HitCheck_BaseObj_Box(bulletList[bu], hitBoxList[box]))
					hitBoxList.erase(hitBoxList.begin() + box);
			}
		}

		std::vector<Explosion*>explosionList = _pBullet->GetBulletList()[p2].m_ExplosionList;
		// �����̃��[�v
		for (int ex = 0; ex < explosionList.size(); ex++)
		{
			// �v���C���[�Ƃ̔���
			std::vector<BaseObject*>& hitCharaList = explosionList[ex]->hitCharObject;
			for (int chara = hitCharaList.size() - 1; chara >= 0; chara--)
			{
				// �v���C���[���ڐG���Ă��Ȃ��Ȃ烊�X�g����폜
				if (!HitCheck_BaseObj(explosionList[ex], hitCharaList[chara]))
					hitCharaList.erase(hitCharaList.begin() + chara);
			}

			// box�Ƃ̔���
			std::vector<Box*>& hitBoxList = explosionList[ex]->hitBoxObject;
			for (int box = hitBoxList.size() - 1; box >= 0; box--)
			{
				// �v���C���[���ڐG���Ă��Ȃ��Ȃ烊�X�g����폜
				if (!HitCheck_BaseObj_Box(explosionList[ex], hitBoxList[box]))
					hitBoxList.erase(hitBoxList.begin() + box);
			}
		}
	}
}

// ���Ƃق��̃I�u�W�F�N�g�̐ڐG�𔻒肷��֐�
bool CollisionManager::HitCheckBox_Other(Box* box)
{
	// �v���C���[�Ƃ̔���
	for (int p = 0; p < _pPlayers.size(); p++)
	{
		BaseCharacter* player = _pPlayers[p];
		if (HitCheck_BaseObj_Box(player, box))
			return true;

		// �e�Ƃ̔���
		std::vector<MainBullet*> bulletList = _pBullet->GetBulletList()[p].m_BulletList;
		for (int b = 0; b < bulletList.size(); b++)
		{
			MainBullet* bullet = bulletList[b];
			// �e����A�N�e�B�u�Ȃ�X�L�b�v
			if (!bullet->GetActive()) continue;

			if (HitCheck_BaseObj_Box(bullet, box))
				return true;
		}
	}

	return false;
}