#include <iostream>
#include "Entity/Entity.h"
#include "Entity/Player/Player.h"
#include "Inventory/Inventory.h"
#include "Inventory/Item/Item.h"
#include "Inventory/Item/Potion/Potion.h"
#include "Inventory/Item/Potion/Heal/HealPotion.h"
#include "Inventory/Item/Potion/Mana/ManaPotion.h"
#include "Inventory/Item/Spells/Fireball/Fireball.h"
#include "Window/Test/Test.h"

int main()
{
	Player* player = new Player("Jean");
	player->GetInventory()->AddItem(new HealPotion(20), 64);
	player->GetInventory()->RemoveItem(new ManaPotion(20), 3);
	player->GetInventory()->AddItem(new HealPotion(20));
	player->GetInventory()->AddItem(new Fireball(10,10));

	Test w = Test(500, 500, "test", player);
	w.Open();
	delete player;
	return 0;
}