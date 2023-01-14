#include "Entity.h"
#include "../UI/Image/UI_Image.h"


#pragma region setter/Getter
float Entity::GetLife() const
{
	return life;
}
float Entity::SetLife(const float _life)
{
	return life = _life;
}
float Entity::GetAttack() const
{
	return attack;
}
float Entity::SetAttack(const float _attack)
{
	return attack = _attack;
}
int Entity::SetLevel(const int _level)
{

	return level = _level;
}
int Entity::GetLevel() const
{
	return level;
}
#pragma endregion setter/Getter
#pragma region methods
void Entity::IsHit(const float _dammage)
{
	life -=_dammage;
}
void Entity::SetPosition(sf::Vector2f _position)
{
	sprite->setPosition(_position);
}
#pragma endregion methods
#pragma region overrideS
sf::FloatRect Entity::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f Entity::Position() const
{
	return sprite->getPosition();
}
#pragma endregion override