#pragma once
#include "../../Potion/Potion.h"
class ManaPotion : public Potion
{
#pragma region constructor
public:
	ManaPotion() = default;
	ManaPotion(const float _value, const int _cost);
#pragma endregion constructor
#pragma region methods
public:
	void OnUse(Entity* _entity) override;
#pragma endregion methods
};

