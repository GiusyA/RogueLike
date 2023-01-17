#pragma once
#include "../Spells.h"
class Fireball : public Spells
{
#pragma region constructor
public:
	Fireball(class Window* _owner, const float _damage, const float _cost);
#pragma endregion constructor
};