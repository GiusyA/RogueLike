#pragma once
#include "../../Potion/Potion.h"
class HealPotion : public Potion
{
#pragma region constructor
public:
	HealPotion() = default;
	HealPotion(const float _value);
#pragma endregion constructor
#pragma region methods
public:
	void OnUse(Entity* _entity) override;
#pragma endregion methods
};

