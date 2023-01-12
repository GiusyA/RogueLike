#include "ManaPotion.h"
ManaPotion::ManaPotion(const float _value) : Potion("../assets/potions/mana.png", "Potion Mana", _value) { }


void ManaPotion::OnUse(Entity* _entity)
{
	Potion::OnUse(_entity);
	//_entity->AddMana(Value());
}