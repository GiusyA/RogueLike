#include <iostream>
#include "Entity/Entity.h"
#include "Entity/Player/Player.h"
#include "Inventory/Inventory.h"
#include "Inventory/Item/Item.h"
#include "Inventory/Item/Potion/Potion.h"
#include "Inventory/Item/Potion/Heal/HealPotion.h"
#include "Inventory/Item/Potion/Mana/ManaPotion.h"
#include "Inventory/Item/Weapons/Sword/IronSword.h"
#include "Inventory/Item/Spells/Fireball/Fireball.h"
#include "Inventory/Item/Spells/Shield/Shield.h"
#include "Inventory/Item/Spells/GodHeal/GodHeal.h"
#include "Inventory/Item/Weapons/MagisStick/MagicStick.h"
#include "Window/Test/Test.h"

int main()
{
	Player* player = new Player("Jean");
	player->GetInventory()->AddItem(new HealPotion(20));
	player->GetInventory()->AddItem(new ManaPotion(20), 3);
	player->GetInventory()->RemoveItem(new HealPotion(20));
	player->GetInventory()->AddItem(new Fireball(10,10));
	player->GetInventory()->AddItem(new IronSword(10,10));
	player->GetInventory()->AddItem(new Shield(10,10));
	player->GetInventory()->AddItem(new MagicStick(10, 50));
	player->GetInventory()->AddItem(new GodHeal(100, 200));
	player->GetInventory()->AddMoney(500);

	Test w = Test(600, 600, "test", player);
	w.Open();
	delete player;
	return 0;
}