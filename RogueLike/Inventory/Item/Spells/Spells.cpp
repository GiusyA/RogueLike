#include "Spells.h"
#include "../../../Entity/Player/Player.h"

Spells::Spells(const std::string _texture, const std::string& _name, const float _damage, const float _cost) : Item(_texture, _name)
{
    name = _name;
    damage = _damage;
    costMana = _cost;
    GetSprite()->setPosition(0, 0);
    GetSprite()->setScale(2.0f, 2.0f);
}

Spells::Spells(const Spells& _copy)
{
    name = _copy.name;
    damage = _copy.damage;
    costMana = _copy.costMana;
}

float Spells::CostMana() const
{
    return costMana;
}

float Spells::Damage() const
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
