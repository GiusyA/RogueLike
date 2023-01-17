#include "Fireball.h"
#include "../../../../Entity/Entity.h"
#include "../../../../Entity/Player/Player.h"
#include "../../Database/ItemDatabase.h"

Fireball::Fireball(Window* _owner, const float _damage, const float _cost) :
	Spells(_owner, "../assets/spells/fireball.png", FIREBALL, true, _damage, _cost)
{
}