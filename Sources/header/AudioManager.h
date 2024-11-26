#pragma once
#include <vector>
#include "DxLib.h"
#include "Const.h"

class AudioManager
{
private:
	std::vector<int> _soundHandle;	// SE�n���h���̉ϒ��z��
	std::vector<int> _bgmHandle;	// BGM�n���h��

public:

	static AudioManager* audio;
	AudioManager();

	~AudioManager();

	void PlaySE(SEName se);

	void PlayLoopBGM(BGMName bgm);

	void StopAllBGM();

	void StopSE(SEName se);

	void StartLoopSE(SEName se);

	void StopAllSound();
};
