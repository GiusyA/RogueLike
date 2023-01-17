#include "GodHeal.h"
#include "../../Database/ItemDatabase.h"

GodHeal::GodHeal(Window* _owner, const float& _heal, const float& _cost)
	: Spells(_owner, "../assets/spells/godheal.png", GODHEAL, false, _heal, _cost)
{

}