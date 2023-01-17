#include "Fireball.h"
#include "../../../../Entity/Entity.h"
#include "../../../../Entity/Player/Player.h"


#pragma region constructor
Fireball::Fireball(const float _damage, const float _cost) :
	Spells("assets/Sprites/spells/fireball.png", "Fireball", true, _damage, _cost)
{
	sprite->setScale(sf::Vector2f(5.355, 5.355));
}
#pragma endregion constructor
#pragma endregion methode
void Fireball::Destruc()
{
	delete sprite;
	sprite = nullptr;
}
void Fireball::SetOrigin(sf::Vector2f _vector)
{
	sprite->setOrigin(_vector);
}
void Fireball::SetPosition(sf::Vector2f _vector)
{
	sprite->setPosition(_vector);
}
sf::Drawable* Fireball::GetDrawable()
{
	return drawable = sprite;
}
#pragma endregion methode
#pragma region override
void Fireball::OnUse(Entity* _entity)
{
	//For each opposent differet attack
}
sf::FloatRect Fireball::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f Fireball::Position() const
{
	return sprite->getPosition();
}
#pragma endregion override