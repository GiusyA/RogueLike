#include "Player.h"
#include "../../Inventory/Inventory.h"
#include "../../UI/Image/UI_Image.h"
#include "../../Window/Window.h"
#include "SFML/Graphics.hpp"

#pragma region constructor/destructor
Player::Player(const std::string _name, const float _life, UI_Image* _image, const float _attack, const int _level, const float _mana, const Inventory* _inventory) : Entity(_name, _life, _image,  _attack, _level)
{
	
	sf::Texture _texture;
	inventory = new Inventory(); //TODO
	mana = mana;
	name = _name;
	image = new UI_Image();

}
Player::Player(const Player& _copy) : Entity( _copy)
{
	inventory = _copy.inventory;
	mana = _copy.mana;
}
Player::~Player()
{
	OnDestroy(isDead);
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
	void Player::Init()
	{
		//TODO Image
	}
#pragma endregion methods
#pragma region override
	void Player::OnDestroy(const bool _isdead)
	{
		if (_isdead)
		{
			delete inventory;
			inventory = nullptr;
		}
	}
#pragma endregion override