#include "Spells.h"
#include "../../../Entity/Player/Player.h"

Spells::Spells(const std::string _texture, const std::string& _name, const bool& _damage, const float _value, const float _costMana, const int _cost)
    : Item(_texture, _name, _cost)
{
    name = _name;
    value = _value;
    costMana = _costMana;
    GetSprite()->setPosition(0, 0);
    GetSprite()->setScale(2.0f, 2.0f);
}

Spells::Spells(const Spells& _copy)
{
    name = _copy.name;
    value = _copy.value;
    costMana = _copy.costMana;
    damage = _copy.damage;
}

float Spells::CostMana() const
{
    return costMana;
}

float Spells::Value() const
{
    return value;
}

bool Spells::IsDamage() const
{
    return damage;
}

void Spells::OnUse(Player* _player)
{
    //_player->RemoveMana(costMana);
}

bool Spells::Equals(const Item* _other) const
{
    return Item::Equals(_other);
}


std::string Spells::ToString() const
{
    return "";
}
