#pragma once
#include "../Spells.h"
class Fireball : public Spells
{
#pragma region constructor
public:
	Fireball(const float _damage, const float _cost);
#pragma endregion constructor

#pragma region methods
public:
	void OnUse(class Player* _player) override;
#pragma endregion methods
};

