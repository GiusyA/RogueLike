#include "Test.h"
#include "../../Inventory/Item/Item.h"
#include "../../Entity/Player/Player.h"
#include <iostream>
#include "../../Inventory/Inventory.h"
#include "../../UI/Image/UI_Image.h"
Test::Test(const int _w, const int _h, const char* _title, Player* _player) :
	Window(_w, _h, _title)
{
	player = _player;
	background = new UI_Image(this, "../assets/inventory/inventory_background.png");
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetPosition(sf::Vector2f(0, 0));
}

Test::~Test()
{
	
}

void Test::OnDraw()
{
	Draw(background->GetSprite());
	player->GetInventory()->DisplayInventory(this, 320, 10, 15);
	player->GetInventory()->DisplaySpells(this, 20, 550, 30);
}

void Test::OnUpdate()
{
}
