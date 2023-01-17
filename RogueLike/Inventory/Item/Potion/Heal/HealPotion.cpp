#include "HealPotion.h"
#include "../../../../Entity/Entity.h"

HealPotion::HealPotion(const float _value): Potion("../assets/potions/heal.png", "Potion Health", _value) { }


void HealPotion::OnUse(Entity* _entity)
{
	Potion::OnUse(_entity);
	_entity->SetLife(Value());
}
