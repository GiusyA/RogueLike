#pragma once
#include "../../Potion/Potion.h"
class ManaPotion : public Potion
{
#pragma region constructor
public:
	ManaPotion() = default;
	ManaPotion(class Window* _owner, const float _value);
#pragma endregion constructor
#pragma region methods
public:
	void OnUse(Player* _player) override;
#pragma endregion methods
};