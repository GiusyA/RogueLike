#include "Test.h"
#include "../../Inventory/Item/Item.h"
#include "../../Entity/Player/Player.h"
#include <iostream>
#include "../../Inventory/Inventory.h"
Test::Test(const int _w, const int _h, const char* _title, Player* _player) :
	Window(_w, _h, _title)
{
	player = _player;
}

Test::~Test()
{
	
}

void Test::OnDraw()
{
	player->GetInventory()->DisplayInventory(this, 50, 10, 100);
}

void Test::OnUpdate()
{
}
