#pragma once
#include "../Spells.h"
class Shield :
    public Spells
{
#pragma region f/p
public:
    Shield(class Window* _owner, const int& _protect, const float& _cost);
#pragma endregion f/p
};
