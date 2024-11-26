#include "../header/AudioManager.h"

// コンストラクタ
// 音声ファイル名を可変長配列に格納
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

// num番目のSEを再生
void AudioManager::PlaySE(SEName se)
{
	PlaySoundMem(_soundHandle[(int)se], DX_PLAYTYPE_BACK, TRUE);
}

// BGMを再生する関数
void AudioManager::PlayLoopBGM(BGMName bgm)
{
	// 再生中でないなら
	if (CheckSoundMem(_bgmHandle[(int)bgm]) == false)
	{
		PlaySoundMem(_bgmHandle[(int)bgm], DX_PLAYTYPE_BACK, TRUE);
	}
}

// SEの停止
void AudioManager::StopSE(SEName se)
{
	StopSoundMem(_soundHandle[(int)se]);
}

// ループ再生
void AudioManager::StartLoopSE(SEName se)
{
	// 再生中でないなら
	if (CheckSoundMem(_soundHandle[(int)se]) == false)
	{
		PlaySoundMem(_soundHandle[(int)se], DX_PLAYTYPE_BACK, TRUE);
	}
}

// すべてのBGMを止める関数
void AudioManager::StopAllBGM()
{
	for (int i = 0; i < _bgmHandle.size(); i++)
	{
		StopSoundMem(_bgmHandle[i]);
	}
}

// すべてのサウンドを止める関数
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