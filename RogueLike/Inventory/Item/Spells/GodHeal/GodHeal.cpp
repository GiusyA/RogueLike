#include "GodHeal.h"

GodHeal::GodHeal(const float& _heal, const int _cost, const float& _costMana)
	: Spells("../assets/spells/godheal.png", GODHEAL, false, _heal, _costMana, _cost)
{

}
