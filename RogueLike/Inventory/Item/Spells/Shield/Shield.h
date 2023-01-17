#pragma once
#include "../Spells.h"
class Shield :
    public Spells
{
#pragma region f/p
public:
    Shield(const int& _protect, const int _cost, const float& _costMana);
#pragma endregion f/p
};

