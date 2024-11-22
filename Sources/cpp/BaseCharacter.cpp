#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
	bullet = new BulletManager();

	hitObject = false;
	dodgeNow = false;

	canLottery = true;

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

// �o���l������
void BaseCharacter::ObserveExp()
{
	// ���x���A�b�v�ɕK�v�Ȍ��𖞂����Ă�����
	if (GetExpValue() >= request)
	{
		// ���x���A�b�v�����玟�̃��x���A�b�v�ɕK�v�ȃR�X�g���グ��
		request += request + 1;

		// �O�̔{���񂱂�܂łɃ��x���A�b�v���Ă�����p���[�A�b�v����I��
		if (levelUpCount % 3 == 0)
		{
			// �p���[�A�b�v�ł���񐔂��ꂠ����
			lotteryPowerCount++;
		}

		// �O�̔{����ł͂Ȃ�������X�e�[�^�X����I��
		else
		{
			// �X�e�[�^�X�A�b�v�ł���񐔂��ꂠ����
			lotteryStatusCount++;
		}
	}

	if (canLottery == true)
	{
		// �ǂ��炩�̒l���u0�v�ł͂Ȃ�������I�����̒��I���s��
		if (lotteryStatusCount != 0 || lotteryPowerCount != 0)
		{
			// �p���[�A�b�v��D��ŋ����ł�����̂̒��I���s��
			lotteryPowerCount > 0 ? LotteryPower() : LotteryStatus();

			// �v���C���[���I�����s���K��������܂Œ��I�𐧌�
			canLottery = false;
		}
	}
}

// �p���[�A�b�v�ł�����̂𒊑I����
void BaseCharacter::LotteryPower()
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
		// auto�^�Ŏ擾���Ă���폜
		auto it = std::find(choicePower.begin(), choicePower.end(), GetRand(choicePower.size()));

		// �z��̗v�f�����g���ė������擾���Ă��̂܂ܔz��̗v�f���폜
		choicePower.erase(it);
	}

	// �I������I�ׂ��Ԃɂ���
	choosePower = true;
}

// �X�e�[�^�X�A�b�v�ł�����̂𒊑I����
void BaseCharacter::LotteryStatus()
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

	// �I������I�ׂ��Ԃɂ���
	chooseStatus = true;
}

void BaseCharacter::ChooseBonus(int selectedButton)
{
	// �����𓾂邱�Ƃ��ł����Ԃ�������
	if (choosePower != 0 || chooseStatus != 0)
	{
		// �p���[�A�b�v�������s��
		if (choosePower)
		{
			// �p���[�A�b�v
			bullet->LevelUpType((BulletType)choicePower[selectedButton], deviceNum);
			choosePower = false;
		}

		// �X�e�[�^�X�A�b�v�������s�� 
		else
		{
			// �X�e�[�^�X�A�b�v
			bullet->LevelUpStatus((BulletStatus)choiceStatus[selectedButton], deviceNum);
			chooseStatus = false;
		}

		// ���I�ł����Ԃɖ߂�
		canLottery = true;
	}

	else { return; }
}

// ����{�^���������ꂽ��ړ����@��Move����DodgeMove�ɐ؂�ւ���
void BaseCharacter::Dodge() { if (canDodge == true)dodgeNow = true; }

// �v���C���[�ɔԍ���U�蕪��
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// �����ł�������ԍ����v���C���[�ԍ��ɐݒ�
	playerNum = playerNumber;
}

Vector2 BaseCharacter::GetPlayerPos() { return status.m_position; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

/// <summary>
/// �t���O��true�ɂȂ��Ă��邩�ǂ����m���߂�
/// </summary>
/// <param name="0">true�ɂȂ��Ă���t���O�͂Ȃ�</param>
/// <param name="1">choosePower��true</param>
/// <param name="2">chooseStatus��true</param>
int BaseCharacter::GetChooceFlag()
{
	//if (choosePower) return 1;
	//if (chooseStatus) return 2;

	return 0;
}

void BaseCharacter::GainExp(int expValue) { exp += expValue; }

int BaseCharacter::GetExpValue() { return exp; }
