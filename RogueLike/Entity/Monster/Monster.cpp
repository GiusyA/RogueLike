#include "Monster.h"
#include "../Player/Player.h"
#include "../../Inventory/Item/Spells/Fireball/Fireball.h"
#include <iostream>



#pragma region constructor/destructor
Monster::Monster()
{	
	Init();
}
Monster::~Monster()
{
	Die();
}
#pragma endregion constructor/destructor
#pragma region methods
void Monster::Delay()
{
	delay++;

	if (delay == 1000.0f)
	{
		
		Attack();
		delay = 0.0f;
	}
}
#pragma endregion methods
#pragma region override
sf::Drawable* Monster::GetDrawable(){
	return drawable = sprite; 
}
void Monster::Die()
{
	if (!isDead) return;
	isDead = false;
	OnDie.Invoke();
}
void Monster::Restart(){ 
	Init(); 
}
void Monster::OnUpdate() 
{
	sprite->setPosition(sprite->getPosition() + sf::Vector2f(speed, 0));
	Collition();
	Delay();
	if (isAttack)
		fireball->SetPosition(fireball->Position() + sf::Vector2f(0, 0.5));
	
	
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
void Monster::Collition()
{
	if (sprite->getPosition().x >= width - collEntity)
	{
		speed = 0 - speed;
		sprite->setPosition(sf::Vector2f(width - collEntity, 0) + sf::Vector2f(speed, 0));
	}
	if (sprite->getPosition().x <= 0)
	{
		speed = 0 - speed;
		sprite->setPosition(sf::Vector2f(0, 0) + sf::Vector2f(speed, 0));
	}

	if (isAttack)
		if (fireball->Position().y >= height)
		{
			isAttack = false;
			IsHit(0.0f);
		}
}
void Monster::Attack()
{
	isAttack = true;
	fireball = new Fireball(0.0f, 0.0f);
	fireball->SetOrigin(sf::Vector2f(0, 0));
	fireball->SetPosition(sf::Vector2f(sprite->getPosition().x, sprite->getPosition().y));
	
}
void Monster::IsHit(const float _dammage)
{
	delete fireball;
	fireball = nullptr;
}
sf::Drawable* Monster::GetDrawableProjectile()
{
	return fireball->GetDrawable();
}
#pragma endregion override
