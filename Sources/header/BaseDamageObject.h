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

    // 初期化
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
    // ダメージ取得
    inline float GetDamage() const { return damage; }
};

