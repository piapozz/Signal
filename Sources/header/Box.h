#pragma once
#include "BaseObject.h"

class Box : public BaseObject
{
private:

	Vector2 _vertex[4];		// í∏ì_ÇÃç¿ïW

public:

	Box(Vector2 pos);
	Box(Vector2 pos, float life);
	~Box(){}

	void Draw();

	void CalVertexPos();
	Vector2 GetNormDir();
	Vector2 GetVertexPos(int n);
};
