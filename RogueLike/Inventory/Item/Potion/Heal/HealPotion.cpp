#include "HealPotion.h"
#include "../../../../Entity/Entity.h"

HealPotion::HealPotion(const float _value, const int _cost): Potion("../assets/potions/heal.png", HEAL_POTION, _value, _cost) { }


void HealPotion::OnUse(Entity* _entity)
{
	Potion::OnUse(_entity);
	//_entity->AddLife(Value());
}
