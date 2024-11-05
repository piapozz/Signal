#pragma once
#include "BaseObject.h"

class Box : public BaseObject
{
private:

	Vector2 _vertex[4];		// 頂点の座標
	bool _isWall;			// 壁かどうかのフラグ
	int _untilRevivalCount = REVIVAL_TIME;
	float _maxLife;
	int _exp;

public:

	Box(Vector2 pos);
	Box(Vector2 pos, float life);
	~Box(){}

	void Draw();

	void Move(){}

	void CalVertexPos();
	Vector2 GetNormDir(Vector2 pos);
	Vector2 GetVertexPos(int n);
	void RevivalBox();
	void DestroyBox();
	void RevivalCount();
	bool GetIsWall() { return _isWall; }
	int GetRevivalCount() { return _untilRevivalCount; }
	int GetExp() { return _exp; }
};
