#pragma once
#include <vector>
#include "DxLib.h"

class AudioManager
{
private:
	std::vector<int> _soundHandle;	// SE�n���h���̉ϒ��z��
	std::vector<int> _bgmHandle;	// BGM�n���h��

public:

	static AudioManager* audio;
	AudioManager();

	~AudioManager();

	void PlaySE(int num);

	void PlayLoopBGM(int num);

	void StopAllBGM();

	void StopSE(int num);

	void StartLoopSE(int num);

	void StopAllSound();
};
