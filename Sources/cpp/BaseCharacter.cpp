#include "../header/BaseCharacter.h"

BaseCharacter::BaseCharacter(BulletManager* bulletManager)
{
	canDodge = true;
	canLottery = true;
	playerBomb = false;
	request = 1;
	status.m_shapeSize = BOX_SIZE / 4.0f;
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
		// �ړ��x�N�g���̒������v�Z
		vecLength = sqrt(pow(dodgeVec.x, 2.0f) + pow(dodgeVec.y, 2.0f));

		// ���K�����ꂽ�ړ��x�N�g���ɃX�s�[�h�������Ď��̈ʒu���v�Z
		status.m_nextPosition.x = status.m_position.x + (dodgeVec.x / vecLength) * dodgeSpeed;
		status.m_nextPosition.y = status.m_position.y + (dodgeVec.y / vecLength) * dodgeSpeed;

		// �������
		if (GetNowCount() >= dodgeMoveCount + DODGE_MOVETIME)
		{
			// �����Ԃ�����
			dodgeNow = false;
			// ���G������
			isInvincible = false;
		}
	}

	// �ʏ�ړ�
	else
	{
		if (moveVec.x != 0.0f || moveVec.y != 0.0f)
		{
			// �ړ��x�N�g���̒������v�Z
			vecLength = sqrt(pow(moveVec.x, 2.0f) + pow(moveVec.y, 2.0f));

			// ���K�����ꂽ�ړ��x�N�g���ɃX�s�[�h�������Ď��̈ʒu���v�Z
			status.m_nextPosition.x = status.m_position.x + (moveVec.x / vecLength) * speed;
			status.m_nextPosition.y = status.m_position.y + (moveVec.y / vecLength) * speed;

			// printfDx("nextPosition %f", status.m_nextPosition.x);
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
	printfDx("%d\n", choiceStatus.size());
	//printfDx("LevelUpCount%d\n", levelUpCount);
	//printfDx("lotteryPowerCount%d\n", lotteryPowerCount);
	//printfDx("lotteryStatusCount%d\n", lotteryStatusCount);
	//printfDx("choicePowerArraySize%d\n", choicePower.size());
	//printfDx("choiceStatusArraySize%d\n", choiceStatus.size());
	//printfDx("Flag%d\n", GetChooceFlag());

	// ���x���A�b�v�ɕK�v�Ȍ��𖞂����Ă�����
	if (GetExpValue() >= request)
	{
		AudioManager::GetInstance().PlaySE(SEName::LEVELUP);

		// �o���l�����Z�b�g
		exp -= request;

		// ���x���A�b�v�����玟�̃��x���A�b�v�ɕK�v�ȃR�X�g���グ��
		request = request + 1;

		levelUpCount++;

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

	// ���I���ł����Ԃ�������
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
	// ������
	// choicePower = DeleteVector(choicePower);
	choicePower.clear();

	// �񋓑�MAX���̂������ϒ��z��̏�����
	for (int i = 0; i < (int)BulletType::MAX; i++)
	{
		// ����ɒB���Ă��ނ�z��Ɋ܂߂Ȃ�
		if (LEVEL_MAX > bulletManager->GetBulletList()[deviceNum].m_BulletType[i])
		{
			// �ϒ��z��ɗv�f��ǉ�
			choicePower.push_back(i);
		}
	}

	// BulletType::NORMAL���폜 �ibegin() �Ő擪���폜�j
	choicePower.erase(choicePower.begin());

	// ���݂̔z��̑傫������\�������������������āA��菜��������for������
	for (int i = 0; i < choicePower.size() - CHOICE_POWER_MAX; i++)
	{
		// auto�^�Ŏ擾���Ă���폜
		// auto it = std::find(choicePower.begin(), choicePower.end(), GetRand(choicePower.size() - 1));

		// �z��̗v�f�����g���ė������擾���Ă��̂܂ܔz��̗v�f���폜
		choicePower.erase(choicePower.begin() + GetRand(choicePower.size() - 1));
	}

	// ���I����񐔂���񌸂炷
	lotteryPowerCount--;

	// �I������I�ׂ��Ԃɂ���
	choosePower = true;
}

// �X�e�[�^�X�A�b�v�ł�����̂𒊑I����
void BaseCharacter::LotteryStatus()
{
	// ������
	// choiceStatus = DeleteVector(choiceStatus);
	choiceStatus.clear();

	// MAX���̂������ϒ��z��̏�����
	for (int i = 0; i < (int)BulletStatus::MAX; i++)
	{
		// ����ɒB���Ă��ނ�z��Ɋ܂߂Ȃ�
		if (LEVEL_MAX > bulletManager->GetBulletList()[deviceNum].m_BulletStatus[i])
		{
			// �ϒ��z��ɗv�f��ǉ�
			choiceStatus.push_back(i);
		}
	}

	//// ���݂̔z��̑傫������\�������������������āA��菜��������for������
	//for (int i = 0; i < choiceStatus.size() - CHOICE_POWER_MAX; i++)
	//{
	//	auto it = std::find(choiceStatus.begin(), choiceStatus.end(), GetRand(choiceStatus.size()));

	//	// �z��̗v�f�����g���ė������擾���Ă��̂܂ܔz��̗v�f���폜
	//	choiceStatus.erase(it);
	//}

	// ���I����񐔂���񌸂炷
	lotteryStatusCount--;

	// �I������I�ׂ��Ԃɂ���
	chooseStatus = true;
}

void BaseCharacter::ChooseBonus(int selectedButton)
{
	// �����𓾂邱�Ƃ��ł����Ԃ�������
	if (choosePower != false || chooseStatus != false)
	{
		// ����ɒB���Ă�����X�L�b�v
		if (choiceStatus.size() == 0)
		{
			canLottery = true;
			chooseStatus = false;
		}
		// ����ɒB���Ă�����X�L�b�v
		if (choicePower.size() == 0)
		{
			canLottery = true;
			choosePower = false;
		}

		if (selectedButton != (int)Cardinal::MAX)
		{
			// �p���[�A�b�v�������s��
			if (choosePower)
			{
				// ���g���Ȃ�������I���𖳌��ɂ���
				if (choicePower.size() > selectedButton)
				{
					// �p���[�A�b�v
					bulletManager->LevelUpType((BulletType)choicePower[selectedButton], deviceNum);
					// ���I�ł����Ԃɖ߂�
					canLottery = true;

					AudioManager::GetInstance().PlaySE(SEName::LEVELUP_DECIDE);

					choosePower = false;
				}
			}

			// �X�e�[�^�X�A�b�v�������s�� 
			else if(chooseStatus)
			{
				// ���g���Ȃ�������I���𖳌��ɂ���
				if (choiceStatus.size() > selectedButton)
				{
					// �X�e�[�^�X�A�b�v
					bulletManager->LevelUpStatus((BulletStatus)choiceStatus[selectedButton], deviceNum);
					// ���I�ł����Ԃɖ߂�
					canLottery = true;

					AudioManager::GetInstance().PlaySE(SEName::LEVELUP_DECIDE);

					chooseStatus = false;
				}
			}
		}
	}

	else { return; }
}

// ����{�^���������ꂽ��ړ����@��Move����DodgeMove�ɐ؂�ւ���
void BaseCharacter::Dodge()
{
	// ����������ꂽ�Ȃ�N�[���^�C�����オ���Ă��邩���m�F
	if (canDodge == true)
	{
		// �����Ԃł͂Ȃ������������J�n
		if (dodgeNow != true)
		{
			// �ړ�������ۑ�
			dodgeVec = moveVec;

			// �ړ��������Ȃ������������Ȃ�
			if (dodgeVec.x != 0 || dodgeVec.y != 0)
			{
				// �v�����J�n
				dodgeMoveCount = GetNowCount();

				// �N�[���^�C���𔭐�������
				dodgeCooltime = GetNowCount();

				// ���ʉ���炷
				AudioManager::GetInstance().PlaySE(SEName::DODGE);

				// ��𒆂ɏ�Ԃ�ύX
				dodgeNow = true;

				// ���G�ɂ���
				isInvincible = true;

				// ���s�\��Ԃɂ���
				canDodge = false;
			}
		}
	}
}

void BaseCharacter::DodgeCoolTime()
{
	// ������ł��Ȃ��Ȃ�����N�[���^�C�����J�n
	if (canDodge == false)
	{
		// 
		if (GetNowCount() >= dodgeCooltime + DODGE_COOLTIME)
		{
			canDodge = true;
		}
	}

}

//// �z��̒��g���폜
//std::vector<int>DeleteVector(std::vector<int> vector)
//{
//	// �z��̑傫�����J��Ԃ��Ē��g���폜����
//	for (int i = 0; i < vector.size(); i++)
//	{
//		vector.erase(vector.begin());
//	}
//
//	return vector;
//}

// �v���C���[�ɔԍ���U�蕪��
void BaseCharacter::SetPlayerNum(int playerNumber)
{
	// �����ł�������ԍ����v���C���[�ԍ��ɐݒ�
	playerNum = playerNumber;
}

void BaseCharacter::SetSurvival() 
{
	// �̗͂�0�ɂȂ����Ƃ��v���C���[�͎��ɂ܂�
	if (status.m_life <= 0 && playerBomb != true)
	{
		// ���Ԃ�ۑ�
		playerBombCount = GetNowCount();

		// ���������s
		BaseChamber::ExplosionContainer temp;
		temp.expansionRange = 5;
		temp.time = PLAYER_BOMB_TIME / 1000;

		bulletManager->CreateExplosion(status, temp);

		// �v���C���[�����t���O�𓮂���
		playerBomb = true;
	}

	// �������I��������A�v���C���[�����S������
	if (playerBomb == true && GetNowCount() >= playerBombCount + PLAYER_BOMB_TIME)status.m_isActive = false;
}

Vector2 BaseCharacter::GetPlayerPos() { return status.m_position; }

bool BaseCharacter::GetIsPlayer() { return isPlayer; }

bool BaseCharacter::GetIsInvincible() { return isInvincible; }

/// <summary>
/// �t���O��true�ɂȂ��Ă��邩�ǂ����m���߂�
/// </summary>
/// <param name="0">true�ɂȂ��Ă���t���O�͂Ȃ�</param>
/// <param name="1">choosePower��true</param>
/// <param name="2">chooseStatus��true</param>
int BaseCharacter::GetChooceFlag()
{
	if (choosePower) return 1;
	if (chooseStatus) return 2;

	return 0;
}

void BaseCharacter::GainExp(int expValue) { exp += expValue; }

int BaseCharacter::GetExpValue() { return exp; }
int BaseCharacter::GetRequestValue() { return request; }
