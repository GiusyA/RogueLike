#include "Shield.h"
#include "../../Database/ItemDatabase.h"

Shield::Shield(Window* _owner, const int& _protect, const float& _cost)
	: Spells(_owner, "../assets/spells/shield.png", SHIELD, false, _protect, _cost)
{
}