#include "../header/AudioManager.h"

// �R���X�g���N�^
// �����t�@�C�������ϒ��z��Ɋi�[
AudioManager::AudioManager()
{
	_bgmHandle.push_back(LoadSoundMem("Resource/mainBGM.mp3"));
	_bgmHandle.push_back(LoadSoundMem("Resource/titleBGM.mp3"));

	_soundHandle.push_back(LoadSoundMem("Resource/bound.mp3"));			// 0
	_soundHandle.push_back(LoadSoundMem("Resource/move.mp3"));			// 1
	_soundHandle.push_back(LoadSoundMem("Resource/shoot.mp3"));			// 2
	_soundHandle.push_back(LoadSoundMem("Resource/destroyBullet.mp3"));	// 3
	_soundHandle.push_back(LoadSoundMem("Resource/rotate.mp3"));		// 4
	_soundHandle.push_back(LoadSoundMem("Resource/destroy.mp3"));		// 5
	_soundHandle.push_back(LoadSoundMem("Resource/clear.mp3"));			// 6
	_soundHandle.push_back(LoadSoundMem("Resource/gameover.mp3"));		// 7
	_soundHandle.push_back(LoadSoundMem("Resource/cursor.mp3"));		// 8
	_soundHandle.push_back(LoadSoundMem("Resource/enter.mp3"));			// 9
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
void AudioManager::PlaySE(int num)
{
	PlaySoundMem(_soundHandle[num], DX_PLAYTYPE_BACK, TRUE);
}

// BGM���Đ�����֐�
void AudioManager::PlayLoopBGM(int num)
{
	// �Đ����łȂ��Ȃ�
	if (CheckSoundMem(_bgmHandle[num]) == false)
	{
		PlaySoundMem(_bgmHandle[num], DX_PLAYTYPE_BACK, TRUE);
	}
}

// SE�̒�~
void AudioManager::StopSE(int num)
{
	StopSoundMem(_soundHandle[num]);
}

// ���[�v�Đ�
void AudioManager::StartLoopSE(int num)
{
	// �Đ����łȂ��Ȃ�
	if (CheckSoundMem(_soundHandle[num]) == false)
	{
		PlaySoundMem(_soundHandle[num], DX_PLAYTYPE_BACK, TRUE);
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