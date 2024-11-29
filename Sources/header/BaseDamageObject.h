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

    // èâä˙âª
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
    // É_ÉÅÅ[ÉWéÊìæ
    float GetDamage() { return damage; }
};

