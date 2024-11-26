#pragma once
#include "BaseObject.h"

class Box : public BaseObject
{
private:

	Vector2 _vertex[4];		// ���_�̍��W
	bool _isWall;			// �ǂ��ǂ����̃t���O
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
	Vector2 GetNormDir(Vector2 hitPos) override;		// �@����Ԃ��֐�
	Vector2 GetVertexPos(int n);			// ���_���W��Ԃ��֐�
	void RevivalBox();
	void DestroyBox();
	void RevivalCount();
	bool GetIsWall() { return _isWall; }
	int GetRevivalCount() { return _untilRevivalCount; }
	int GetExp() { return _exp; }
};
