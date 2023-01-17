#include "Player.h"
#include "../../Inventory/Inventory.h"
#include "../../Window/Window.h"
#include "../../Time/Time.h"
#include "../../Input/Input.h"

#include "../../Inventory/Item/Spells/Fireball/Fireball.h"
#include <iostream>

#pragma region constructor/destructor
Player::Player()
{
	Init();
}
Player::~Player()
{
	if (isGameOver)
		Die();
	Restart();
}
#pragma endregion constructor/destructor
#pragma region setter/getter
	float Player::GetMana() const
	{
		return mana;
	}
	float Player::SetMana(const float _mana)
	{
		return mana = _mana;
	}
	Inventory* Player::GetInventory()
	{
		return inventory;
	}
	void Player::SetInventory(Inventory* _inventory)
	{
		//TODO Inventory
	}
#pragma endregion setter/getter
#pragma region methods
	bool Player::IsGameOver()
	{
		return isGameOver = true;
	}
	void Player::Action()
	{
		if (Input::IsKeyDown(sf::Keyboard::Z))
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(0, -10));
		else if (Input::IsKeyDown(sf::Keyboard::Q))
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(-10, 0));
		else if (Input::IsKeyDown(sf::Keyboard::S))
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(0, 10));
		else if (Input::IsKeyDown(sf::Keyboard::D))
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(10, 0));
		if (Input::IsKeyDown(sf::Keyboard::A))
			Attack();
	}
#pragma endregion methods
#pragma region override
	sf::Drawable* Player::GetDrawable()
	{
		return drawable = sprite;
	}
	void Player::Die() {
		
	} 
	void Player::Restart()
	{
		if (!isDead) return;
		isDead = false;
		OnDie.Invoke();
		Init();
	}
	void Player::OnUpdate()
	{  
		Action();
		Collition();
		if (isAttack)
			fire[0]->SetPosition(fire[0]->Position() + sf::Vector2f(0, -0.5));
	}
	void Player::Init()
	{
		sprite = new sf::Sprite();
		texture = new sf::Texture();
		if (texture->loadFromFile("assets/Sprites/Player/player.png"))
			sprite->setTexture(*texture);
		else
		{
			std::cout << "Impossible to load!" << std::endl;
			return;
		}
		sprite->setOrigin(sf::Vector2f(0, 0));
		sprite->setPosition(sf::Vector2f(500.0f, 500.0f));
		sprite->setScale(sf::Vector2f(5.355, 5.355));

	}
	sf::FloatRect Player::GetGlobalBounds() const
	{
		return sprite->getGlobalBounds();
	}
	sf::Vector2f Player::Position() const
	{
		return sprite->getPosition();
	}
	void Player::Collition()
	{
		if (isAttack)
			if (fire[0]->Position().y >= height)
			{
				isAttack = false;
				IsHit(0.0f);
			}

		if (sprite->getPosition().x <= 0)
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(5, 0));
		if (sprite->getPosition().y <= 0)
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(0, 5));
		if (sprite->getPosition().x >= width - collEntity)
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(-5, 0));
		if (sprite->getPosition().y <= 0)
			sprite->setPosition(sprite->getPosition() + sf::Vector2f(0, -5));
	}
	void Player::Attack()
	{
		isAttack = true;
		fireball = new Fireball(0.0f, 0.0f);
		fire.push_back(fireball);
		fire[0]->SetOrigin(sf::Vector2f(0, 0));
		fire[0]->SetOrigin(sf::Vector2f(0, 0));
		fire[0]->SetPosition(sf::Vector2f(sprite->getPosition().x, sprite->getPosition().y));

	}
	void Player::IsHit(const float _dammage)
	{
		fire[0]->Destruc();
	}
	sf::Drawable* Player::GetDrawableProjectile()
	{
		return fire[0]->GetDrawable();
	}
#pragma endregion override