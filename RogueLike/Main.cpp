#include <iostream>
#include "Entity/Entity.h"
#include "Entity/Player/Player.h"
#include "Inventory/Inventory.h"
#include "Inventory/Item/Item.h"
#include "Inventory/Item/Heal/Heal.h"

int main()
{
	Player* player = new Player("Jean");
	Inventory* inv = new Inventory(player);
	inv->AddItem(new Heal("heal"));
	return 0;
}