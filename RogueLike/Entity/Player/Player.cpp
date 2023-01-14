#include "Player.h"
#include "../../Inventory/Inventory.h"
#include "../../Window/Window.h"
#include "../../Time/Time.h"
#include <iostream>

#pragma region constructor/destructor
Player::Player()
{
	Init();
}
Player::~Player()
{
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
#pragma endregion methods
#pragma region override
	sf::Drawable* Player::GetDrawable()
	{
		 sf::Drawable* _sprite = sprite;
		return _sprite;
	}

	void Player::Die() {} //Pas touche die
	void Player::Restart()
	{
		if (!isDead) return;
		isDead = false;
		OnDie.Invoke();
		Init();
	}
	void Player::OnUpdate(){}
	void Player::Init()
	{
		sprite = new sf::Sprite();
		texture = new sf::Texture();
		if (texture->loadFromFile("assets/Sprites/Heros/mage.png"))
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
#pragma endregion override