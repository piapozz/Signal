#pragma once
#include "BaseObject.h"

class Box : public BaseObject
{
private:

	Vector2 _vertex[4];		// ���_�̍��W
	bool _isWall;			// �ǂ��ǂ����̃t���O

public:

	Box(Vector2 pos);
	Box(Vector2 pos, float life);
	~Box(){}

	void Draw();

	void Move(){}

	void CalVertexPos();
	Vector2 GetNormDir();
	Vector2 GetVertexPos(int n);
	void DestroyBox();
	bool GetIsWall() { return _isWall; }
};
