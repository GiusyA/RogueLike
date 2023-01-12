#include "Weapons.h"

Weapons::Weapons(const std::string _texture, const std::string& _name, const float _damage, const float _cost)	
	: Item(_texture, _name)
{
	name = _name;
	damage = _damage;
	cost = _cost;
}

Weapons::Weapons(const Weapons& _copy)
{
	name = _copy.name;
		damage = _copy.damage;
		cost = _copy.cost;
}

Weapons::~Weapons()
{
}

float Weapons::Cost() const
{
	return cost;
}

float Weapons::Damage() const
{
	return damage;
}

void Weapons::OnUse(Player* _player)
{
}

bool Weapons::Equals(const Item* _other) const
{
	return Item::Equals(_other);
}

std::string Weapons::ToString() const
{
	return  "";
}
