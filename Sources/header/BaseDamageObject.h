#pragma once
#include "BaseObject.h"

class BaseDamageObject :
    public BaseObject
{
protected:

    float damage;
    std::vector<BaseObject> hitObject;

public:

    // ������
    BaseDamageObject() :damage(0) { hitObject.clear(); }
    ~BaseDamageObject(){}

    // ���������I�u�W�F�N�g��ǉ�
    void AddHitObject(BaseObject hit) { hitObject.push_back(hit); }

    // �_���[�W�擾
    float GetDamage() { return damage; }
};

