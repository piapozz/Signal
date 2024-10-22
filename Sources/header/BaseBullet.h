#pragma once
#include <math.h>
#include <vector>

#include "Dxlib.h"
#include "BaseObject.h"

class BaseBullet
{
private:

	// �e�ۂ̐F
	const int _BULLET_COLOR = GetColor(255, 0, 0);


public:

	// �C�j�V�����C�U
	BaseBullet(){ };

	// �f�X�g���N�^
	~BaseBullet() {};

	// �`��֐�
	void Draw();

	// ���W�X�V�֐�
	void Move();
};