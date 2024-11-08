#pragma once
#include "BaseObject.h"

class BaseDamageObject :
    public BaseObject
{
protected:

    float damage;
    std::vector<BaseObject> hitObject;

public:

    BaseDamageObject() :damage(0) { hitObject.clear(); }

    float GetDamage() { return damage; }
};

