#include "ObjectShoot.h"
#include <iostream>


#pragma region methods
void ObjectShoot::Move(const float _missileSpeed)
{
	if(isShot)
		circle->setPosition(circle->getPosition()+ sf::Vector2f(0, _missileSpeed));
}
void ObjectShoot::Shoot()
{
	circle = new sf::CircleShape(50, 50);
	circle->getFillColor().Red;

}
bool ObjectShoot::IsShot()
{
	return isShot = true;
}
bool ObjectShoot::GetShot()
{
	return isShot;
}
bool ObjectShoot::IsDestroy()
{
	return isDestroy = true;
}
sf::CircleShape* ObjectShoot::ThisCircleShape()
{
	return circle;
}
void ObjectShoot::Destroy()
{
	if (isDestroy)
	{
		isDestroy = false;
		isShot = false;
		delete circle;
		circle = nullptr;
	}
	
}
#pragma endregion methods
#pragma region override
void ObjectShoot::OnCollisionEnter(GameObject* _other)
{
	if (GetGlobalBounds() == _other->GetGlobalBounds())
		IsDestroy();
}
void ObjectShoot::SetPosition(sf::Vector2f _position)
{
	 circle->setPosition(sf::Vector2f(_position));
}
void ObjectShoot::OnUpdate()
{
	Shoot();
	Destroy();
}
sf::FloatRect ObjectShoot::GetGlobalBounds() const
{
	return circle->getGlobalBounds();
}
sf::Vector2f ObjectShoot::Position() const
{
	return circle->getPosition();
}
#pragma endregion override

