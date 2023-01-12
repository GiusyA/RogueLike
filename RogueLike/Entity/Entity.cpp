#include "Entity.h"

Entity::Entity(std::string _name, const float _life)
{
	name = _name;
	life = _life;
}

std::string Entity::GetName() const
{
	return name;
}

int Entity::GetLife()
{
	return life;
}

void Entity::AddLife(float _value)
{
	int _life = life + _value;
	if (_life > 100.0f)
		life = 100.0f;
	else life = _life;
}
