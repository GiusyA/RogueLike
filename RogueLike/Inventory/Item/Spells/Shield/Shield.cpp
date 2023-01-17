#include "Shield.h"

Shield::Shield(const int& _protect, const int _cost, const float& _costMana)
	: Spells("../assets/spells/shield.png", SHIELD, false,  _protect, _costMana, _cost)
{
}
