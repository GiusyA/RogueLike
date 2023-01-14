#include "Monster.h"
#include <iostream>

#pragma region constructor/destructor
Monster::Monster()
{	
	Init();
}
Monster::~Monster()
{
	Restart();
}
#pragma endregion constructor/destructor
#pragma region methods
#pragma endregion methods
#pragma region override
sf::Drawable* Monster::GetDrawable()
{
	sf::Drawable* _sprite = sprite;
	return _sprite;
}
void Monster::Die()
{
	if (!isDead) return;
	isDead = false;
	OnDie.Invoke();
}
void Monster::Restart(){}
void Monster::OnUpdate()
{
}
void Monster::Init()
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (texture->loadFromFile("assets/Sprites/Monster/ghost.png"))
		sprite->setTexture(*texture);
	else
	{
		std::cout << "Impossible to load!" << std::endl;
		return;
	}

	sprite->setOrigin(sf::Vector2f(0, 0));
	sprite->setPosition(sf::Vector2f(0, 0));
	sprite->setScale(sf::Vector2f(5.355, 5.355));
}
sf::FloatRect Monster::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f Monster::Position() const
{
	return sprite->getPosition();
}
#pragma endregion override
