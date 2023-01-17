#include "ManaPotion.h"
#include "../../../../Entity/Player/Player.h"
#include "../../Database/ItemDatabase.h"

ManaPotion::ManaPotion(Window* _owner, const float _value) : Potion(_owner, "../assets/potions/mana.png", MANA_POTION, _value) { }


void ManaPotion::OnUse(Player* _player)
{
	Potion::OnUse(_player);
	_player->AddMana(Value());
}