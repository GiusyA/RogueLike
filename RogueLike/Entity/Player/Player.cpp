#include "Player.h"
#include "../../Inventory/Inventory.h"
#include "../../UI/Image/UI_Image.h"
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
