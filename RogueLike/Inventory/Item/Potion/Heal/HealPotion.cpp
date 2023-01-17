#include "HealPotion.h"
#include "../../../../Entity/Entity.h"
#include "../../../../Entity/Player/Player.h"
#include "../../Database/ItemDatabase.h"

HealPotion::HealPotion(Window* _owner, const float _value) : Potion(_owner, "../Assets/Potions/heal.png", HEAL_POTION, _value) { }


void HealPotion::OnUse(Player* _player)
{
	Potion::OnUse(_player);
	_player->AddLife(Value());
}