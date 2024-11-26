#pragma once
#include <vector>
#include "DxLib.h"
#include "Const.h"

class AudioManager
{
private:
	std::vector<int> _soundHandle;	// SEハンドルの可変長配列
	std::vector<int> _bgmHandle;	// BGMハンドル

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
