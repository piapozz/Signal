#include "../header/AudioManager.h"

// �R���X�g���N�^
// �����t�@�C�������ϒ��z��Ɋi�[
AudioManager::AudioManager()
{
	for (int i = 0; i < (int)BGMName::MAX; i++)
	{
		_bgmHandle.push_back(LoadSoundMem(BGM_ADRESS[i].c_str()));
	}

	for (int i = 0; i < (int)SEName::MAX; i++)
	{
		_soundHandle.push_back(LoadSoundMem(SOUND_ADRESS[i].c_str()));
	}
}

AudioManager::~AudioManager()
{
	for (int i = 0; i < _bgmHandle.size(); i++)
	{
		DeleteSoundMem(_bgmHandle[i]);
	}

	for (int i = 0; i < _soundHandle.size(); i++)
	{
		DeleteSoundMem(_soundHandle[i]);
	}
}

// num�Ԗڂ�SE���Đ�
void AudioManager::PlaySE(SEName se)
{
	PlaySoundMem(_soundHandle[(int)se], DX_PLAYTYPE_BACK, TRUE);
}

// BGM���Đ�����֐�
void AudioManager::PlayLoopBGM(BGMName bgm)
{
	// �Đ����łȂ��Ȃ�
	if (CheckSoundMem(_bgmHandle[(int)bgm]) == false)
	{
		PlaySoundMem(_bgmHandle[(int)bgm], DX_PLAYTYPE_BACK, TRUE);
	}
}

// SE�̒�~
void AudioManager::StopSE(SEName se)
{
	StopSoundMem(_soundHandle[(int)se]);
}

// ���[�v�Đ�
void AudioManager::StartLoopSE(SEName se)
{
	// �Đ����łȂ��Ȃ�
	if (CheckSoundMem(_soundHandle[(int)se]) == false)
	{
		PlaySoundMem(_soundHandle[(int)se], DX_PLAYTYPE_BACK, TRUE);
	}
}

// ���ׂĂ�BGM���~�߂�֐�
void AudioManager::StopAllBGM()
{
	for (int i = 0; i < _bgmHandle.size(); i++)
	{
		StopSoundMem(_bgmHandle[i]);
	}
}

// ���ׂẴT�E���h���~�߂�֐�
void AudioManager::StopAllSound()
{
	for (int i = 0; i < _bgmHandle.size(); i++)
	{
		StopSoundMem(_bgmHandle[i]);
	}

	for (int i = 0; i < _soundHandle.size(); i++)
	{
		StopSoundMem(_soundHandle[i]);
	}
}