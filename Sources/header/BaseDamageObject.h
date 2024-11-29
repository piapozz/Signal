#pragma once
#include "BaseObject.h"
#include "Box.h"

class BaseDamageObject :
    public BaseObject
{
protected:

    float damage;

public:
    std::vector<Box*> hitBoxObject;
    std::vector<BaseObject*> hitCharObject;

    // ������
    BaseDamageObject() : damage(0)
    {
        hitBoxObject.clear();
        hitCharObject.clear();
    }

    ~BaseDamageObject() 
    {
        for (int i = 0; i < hitBoxObject.size(); i++) 
        {
            delete hitBoxObject[i];
        }
        for (int i = 0; i < hitCharObject.size(); i++)
        {
            delete hitCharObject[i];
        }
    }
    // �_���[�W�擾
    float GetDamage() { return damage; }
};

