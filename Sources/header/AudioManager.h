#pragma once
#include <vector>
#include "DxLib.h"
#include "Const.h"

class AudioManager
{
private:
	std::vector<int> _soundHandle;	// SEハンドルの可変長配列
	std::vector<int> _bgmHandle;	// BGMハンドル

	// static AudioManager* audioManager;

	const char* SOUND_ADRESS[(int)SEName::MAX]
	{
		"Resources/Audio/Shot.mp3",
		"Resources/Audio/Impact.mp3",
		"Resources/Audio/LevelUp.mp3",
		"Resources/Audio/Levelup_Decide.mp3",
		"Resources/Audio/Explosion.mp3",
		"Resources/Audio/Damage.mp3",
		"Resources/Audio/Dodge.mp3",
		"Resources/Audio/Reflect.mp3",
		"Resources/Audio/Bomb.mp3",
		"Resources/Audio/Cursor_Decide.mp3",
		"Resources/Audio/Cursor_Move.mp3",
		"Resources/Audio/GameEnd.mp3",
	};

	const char* BGM_ADRESS[(int)BGMName::MAX]
	{
		"Resources/Audio/BGM.mp3",
	};

	AudioManager();

	~AudioManager();

public:

	static AudioManager& GetInstance()
	{
		static AudioManager instance; // 初回呼び出し時に1回だけ初期化
		return instance;
	}

	void PlaySE(SEName se);

	int GetNum(SEName se);

	void PlayLoopBGM(BGMName bgm);

	void StopAllBGM();

	void StopSE(SEName se);

	void StartLoopSE(SEName se);

	void StopAllSound();
};
