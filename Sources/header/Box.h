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
	int _graphHandle;

public:

	Box(Vector2 pos, int handle);
	Box(Vector2 pos, float life, int handle);
	~Box(){}

	void Draw();

	void Move(){}

	void CalVertexPos();
	Vector2 GetNormDir(Vector2 hitPos) override;		// 法線を返す関数
	Vector2 GetVertexPos(int n);			// 頂点座標を返す関数
	void RevivalBox();
	void DestroyBox();
	void RevivalCount();
	bool GetIsWall() { return _isWall; }
	int GetRevivalCount() { return _untilRevivalCount; }
	int GetExp() { return _exp; }
};
