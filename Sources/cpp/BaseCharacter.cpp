#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

	hitObject = false;
	dodgeNow = false;

	choiceFlag = false;

	exp = 0;
	request = 3;
	// speed = 1.0f;
}

BaseCharacter::~BaseCharacter()
{

}

// �ʏ�ړ�����
void BaseCharacter::Move()
{
	// ����ړ���������
	if (dodgeNow)
	{
		// �����Ă�������ɋ����I�ɐi��
		status.m_nextPosition.x = (status.m_position.x + cos(status.m_angle)) * dodgeSpeed;
		status.m_nextPosition.y = (status.m_position.y + sin(status.m_angle)) * dodgeSpeed;
	}

	// �ʏ�ړ�
	else
	{
		if (moveVec.x != 0.0f || moveVec.y != 0.0f)
		{
			// �ړ��x�N�g���̒������v�Z
			vecLength = sqrt(pow(moveVec.x, 2.0f) + pow(moveVec.y, 2.0f));

			// ���K�����ꂽ�ړ��x�N�g���ɃX�s�[�h�������Ď��̈ʒu���v�Z
			status.m_nextPosition.x = status.m_position.x + (moveVec.x / vecLength);
			status.m_nextPosition.y = status.m_position.y + (moveVec.y / vecLength);
		}
	}
}

// ������ς���
void BaseCharacter::Rotate(Vector2 stickAngle)
{
	// �ړ���������p�x���v�Z
	if (stickAngle.x != 0.0f || stickAngle.y != 0.0f)
	{
		// �p�x�v�Z���p�x�����W�A���ŕԂ�
		status.m_angle = atan2(stickAngle.y, stickAngle.x) * (180.0f / DX_PI_F);
	}
}

// �v���C���[�ɔԍ���U�蕪��
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// �����ł�������ԍ����v���C���[�ԍ��ɐݒ�
	playerNum = playerNumber;
}

void BaseCharacter::LevelUp()
{
	// ���x���A�b�v�ɕK�v�Ȍ��𖞂����Ă�����
	if (GetExpValue() >= request)
	{
		// ���x���A�b�v�����玟�̃��x���A�b�v�ɕK�v�ȃR�X�g���グ��
		request += 3;

		// �O�̔{���񂱂�܂łɃ��x���A�b�v���Ă�����p���[�A�b�v����I��
		if (levelUpCount % 3)
		{
			// �p���[�A�b�v�ł���񐔂��ꂠ����
			powerUpCount++;

		}

		// �O�̔{����ł͂Ȃ�������X�e�[�^�X����I��
		else
		{
			// �X�e�[�^�X�A�b�v�ł���񐔂��ꂠ����
			statusUpCount++;

		}
	}

	if (choiceFlag == false)
	{
		// ���x���A�b�v�ł���񐔂����ăR���g���[���[�̓��͂��󂯎�茋�ʂ𔽉f������
		// �X�e�[�^�X�A�b�v���s��
		if (statusUpCount > 0 && powerUpCount <= 0)
		{
			// �X�e�[�^�X�A�b�v�̒��I���s��
			StatusUp();
		}

		// �p���[�A�b�v���s��
		else if (powerUpCount > 0)
		{
			// �p���[�A�b�v�̒��I���s��
			PowerUp();
		}
	}
	else
	{
		// UI��`�悷��

	}
}

// �I������
void BaseCharacter::PowerUp()
{
	// MAX���̂������ϒ��z��̏�����
	for (int i = 0; 0 < (int)BulletType::MAX - 1; i++)
	{
		// �ϒ��z��ɗv�f��ǉ�
		choicePower.push_back(i);
	}

	// BulletType::NORMAL���폜 �ibegin() �Ő퓬���폜�j
	choicePower.erase(choicePower.begin());

	// ���݂̔z��̑傫������\�������������������āA��菜��������for������
	for (int i = 0; i < choicePower.size() - CHOICE_POWER_MAX; i++)
	{
		auto it = std::find(choicePower.begin(), choicePower.end(), GetRand(choicePower.size()));

		// �z��̗v�f�����g���ė������擾���Ă��̂܂ܔz��̗v�f���폜
		choicePower.erase(it);
	}

	choiceFlag = true;
}

// �X�e�[�^�X�A�b�v���s��
void BaseCharacter::StatusUp()
{
	// MAX���̂������ϒ��z��̏�����
	for (int i = 0; 0 < (int)BulletType::MAX - 1; i++)
	{
		// �ϒ��z��ɗv�f��ǉ�
		choiceStatus.push_back(i);
	}

	// BulletType::NORMAL���폜 �ibegin() �Ő퓬���폜�j
	choiceStatus.erase(choiceStatus.begin());

	// ���݂̔z��̑傫������\�������������������āA��菜��������for������
	for (int i = 0; i < choiceStatus.size() - CHOICE_POWER_MAX; i++)
	{
		auto it = std::find(choiceStatus.begin(), choiceStatus.end(), GetRand(choiceStatus.size()));

		// �z��̗v�f�����g���ė������擾���Ă��̂܂ܔz��̗v�f���폜
		choiceStatus.erase(it);
	}

	choiceFlag = true;
}

// ����{�^���������ꂽ��ړ����@��Move����DodgeMove�ɐ؂�ւ���
void BaseCharacter::Dodge() { if (canDodge == true)dodgeNow = true; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

void BaseCharacter::GainExp(int expValue) { exp += expValue; }

int BaseCharacter::GetExpValue() { return exp; }
