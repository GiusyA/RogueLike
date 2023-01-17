#include "ManaPotion.h"
ManaPotion::ManaPotion(const float _value, const int _cost) : Potion("../assets/potions/mana.png", MANA_POTION, _value, _cost) { }


void ManaPotion::OnUse(Entity* _entity)
{
	Potion::OnUse(_entity);
	//_entity->AddMana(Value());
}