#pragma once
#include "../Weapons.h"
class IronSword :
    public Weapons
{

#pragma region constructor
public:
    IronSword(const float& _damage, const int& _cost);
#pragma endregion constructor
};

