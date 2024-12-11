#pragma once
#include "BaseObject.h"
#include "Const.h"

class Box : public BaseObject
{
private:

	Vector2 _vertex[4];		// ���_�̍��W
	bool _isWall;			// �ǂ��ǂ����̃t���O
	int _untilRevivalCount = REVIVAL_TIME;
	float _maxLife;
	int _exp;
	float _revivalTime;
	int _hitCount = 0;

public:

	Box(const Vector2& pos, const int& handle);
	Box(const Vector2& pos, const float& life, const float& revivalTime, const int& handle);
	~Box(){}

	void Init();
	void Draw();
	void Move(){}

	void CalVertexPos();
	Vector2 GetNormDir(const Vector2 hitPos) override;		// �@����Ԃ��֐�
	Vector2 GetVertexPos(const int& n);			// ���_���W��Ԃ��֐�
	void RevivalBox();
	void DestroyBox();
	void RevivalCount();
	inline bool GetIsWall() const { return _isWall; }
	inline int GetRevivalCount() const { return _untilRevivalCount; }
	inline int GetExp() const { return _exp; }
	void HitCount();
};
