#include "Potion.h"
#include <iostream>

#pragma region constructor
Potion::Potion(Window* _owner, const char* _texture, const std::string& _name, const float _value) : Item(_owner, _texture, _name, true)
{
	value = _value;
}

Potion::Potion(const Potion& _copy) : Item(_copy)
{
	value = _copy.value;
}
#pragma endregion constructor

#pragma region methods
float Potion::Value() const
{
	return value;
}

std::string Potion::ToString() const
{
	return Item::ToString() + " value: " + std::to_string(value);
}

void Potion::OnUse(Player* _player)
{
	if (Stack() == 0)
		return;
}

bool Potion::Equals(const Item* _other) const
{
	const Potion* _potion = dynamic_cast<const Potion*>(_other);
	if (_potion == nullptr) return false;
	const bool _result = Item::Equals(_other) && value == _potion->value;
	return _result;
}
#pragma endregion methods