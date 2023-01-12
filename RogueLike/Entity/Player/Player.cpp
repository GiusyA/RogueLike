#include "Player.h"
#include "../../Inventory/Inventory.h"
Player::Player(std::string _name) : Entity(_name, 100.f)
{
	inv = new Inventory(this);
}

Player::~Player()
{
}

Inventory* Player::GetInventory()
{
	return inv;
}
