#pragma once
#include "BaseObject.h"

class Box : public BaseObject
{
private:

	Vector2 vertex[4];		// ���_�̍��W

public:

	Box(Vector2 pos);
	Box(Vector2 pos, float life);
	~Box(){}

	void CalVertexPos();
};

