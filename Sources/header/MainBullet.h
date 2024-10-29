#pragma once

#include "NormalChamber..h"
#include "ExplosionChamber..h"
#include "MultipleChamber..h"
#include "PenetrationChamber..h"
#include "TrackingChamber..h"
#include "ReflectionChamber..h"

// ‚»‚ê‚¼‚ê‚ÌŠÖ”‚ğŒÄ‚Ño‚µ‚ÄˆÚ“®‚È‚Ç‚ğ‚·‚é

class MainBullet
{
private:

	// ’eŠÛ‚ÌF
	const int _BULLET_COLOR = GetColor(0, 0, 0);

	typedef struct ShotStatus
	{
		
	};

protected:

	ShotStatus _status;

	int graph = LoadGraph("char* FileName");

	float distance = 0;

public:

	MainBullet();
	~MainBullet();

	// Šp“xC³
	void UpdateAngle();

	// ˆÚ“®
	void Move();

	// ’…’e
	void Impact();

	// Á–Å
	void Destroy();

	// •`‰æ
	void Draw();
};