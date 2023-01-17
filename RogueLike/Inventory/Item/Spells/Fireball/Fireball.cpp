#include "Fireball.h"
#include "../../../../Entity/Entity.h"
#include "../../../../Entity/Player/Player.h"

Fireball::Fireball(const float _damage, const float _cost) : 
	Spells("../assets/spells/fireball.png", "Fireball", true, _damage, 20, _cost)
{
}

void Fireball::OnUse(Player* _player)
{
	//_player->RemoveMana(CostMana());
}
