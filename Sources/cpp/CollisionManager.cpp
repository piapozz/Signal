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
	// �I�u�W�F�N�g�̌`�ŏ����𕪊�
	// �����~�Ȃ�
	if (obj1)
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
	}
	else
	{

	}

	return false;
}

// �ː����ʂ��Ă��邩���C�Ŕ��肷��֐�
bool CollisionManager::CheckBetweenObject(Vector2 pos1, Vector2 pos2, std::vector<Box> boxList)
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
			if (CheckLineCross(pos1, pos2, boxList[i].GetVertexPos(j), boxList[i].GetVertexPos((j + 1) % 4)) == true)
				return false;
		}
	}
	return true;
}

// �����Ɛ�����������Ă��邩�𔻒肷��֐�
bool CollisionManager::CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2)
{

}