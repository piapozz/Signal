#include "../header/CollisionManager.h"
#include "../header/StageManager.h"

// �@��
// �I�u�W�F�N�g���m�̔����BulletBase��ObjectBase�Ƃ̔���

// �x�[�X�I�u�W�F�N�g�ƃx�[�X�I�u�W�F�N�g�̔���
bool CollisionManager::HitCheck(BaseObject obj1, BaseObject obj2)
{
	// �I�u�W�F�N�g�̌`�ŏ����𕪊�
	// �����~�Ȃ�
	if (true)
	{
		// ���W�Ɣ��a
		Vector2 pos1;
		float radius1;
		Vector2 pos2;
		float radius2;

		// �����̍������a�̍��v�ȉ��Ȃ�ڐG
		if (Vector2::Distance(pos1, pos2) >= (radius1 + radius2))
		{
			return true;
		}
	}

	return false;
}

// �ː����ʂ��Ă��邩���C�Ŕ��肷��֐�
bool CollisionManager::CheckBetweenObject(Vector2 pos1, Vector2 pos2)
{
	// ���ׂĂ̔��Ɣ���
	for (int i = 0; i < 1; i++)
	{
		// ��O����
		// ��������̋������ڐG���Ȃ������Ȃ�X�L�b�v
		if (false) continue;

		// ���ׂĂ̕ӂƔ���
		for (int j = 0; j < 4; j++)
		{
			// �ӂ̐���
			Vector2 sideLine;
			// ���C
			Vector2 ray = pos1 - pos2;
			// �ǂ̕ӂƃ��C��������Ă�����ڐG
			if (false)
			{

			}
		}
	}
}

// �����Ɛ�����������Ă��邩�𔻒肷��֐�
bool CollisionManager::CheckLineCross(Vector2 line1pos1, Vector2 line1pos2, Vector2 line2pos1, Vector2 line2pos2)
{

}