#include "Heal.h"
#include "../../../Entity/Entity.h"
Heal::Heal(std::string _name, int _amount) : Item(_name, true, _amount) { }

void Heal::OnUse(Entity* _entity)
{
	Item::OnUse(_entity);
	_entity->AddLife(heal);
}

std::string Heal::ToString() const
{
	return "";
}
