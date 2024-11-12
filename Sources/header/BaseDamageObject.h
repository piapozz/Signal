#pragma once
#include "BaseObject.h"

class BaseDamageObject :
    public BaseObject
{
protected:

    float damage;
    std::vector<BaseObject> hitObject;

public:

    // 初期化
    BaseDamageObject() :damage(0) { hitObject.clear(); }
    ~BaseDamageObject(){}

    // 当たったオブジェクトを追加
    void AddHitObject(BaseObject hit) { hitObject.push_back(hit); }

    // ダメージ取得
    float GetDamage() { return damage; }
};

