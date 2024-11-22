#pragma once
#include "BaseObject.h"

class BaseDamageObject :
    public BaseObject
{
protected:

    float damage;
    std::vector<BaseObject*> hitObject;

public:

    // 初期化
    BaseDamageObject() :damage(0) { hitObject.clear(); }
    ~BaseDamageObject() { hitObject.clear(); }

    // 当たったオブジェクトを追加
    void AddHitObject(BaseObject* hit) { hitObject.push_back(hit); }

    // 当たったオブジェクト履歴を取得
    std::vector<BaseObject*> GetHitObject() { return hitObject; }

    // ダメージ取得
    float GetDamage() { return damage; }
};

