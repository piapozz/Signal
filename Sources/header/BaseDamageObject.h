#pragma once
#include "BaseObject.h"

class BaseDamageObject :
    public BaseObject
{
protected:

    float damage;
    std::vector<BaseObject*> hitObject;

public:

    // ������
    BaseDamageObject() :damage(0) { hitObject.clear(); }
    ~BaseDamageObject() { hitObject.clear(); }

    // ���������I�u�W�F�N�g��ǉ�
    void AddHitObject(BaseObject* hit) { hitObject.push_back(hit); }

    // ���������I�u�W�F�N�g�������擾
    std::vector<BaseObject*> GetHitObject() { return hitObject; }

    // �_���[�W�擾
    float GetDamage() { return damage; }
};

