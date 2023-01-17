#include <iostream>
#include "Entity/Entity.h"
#include "Entity/Player/Player.h"
#include "RogueLike/RogueLike.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	RogueLike rogue = RogueLike();
	rogue.Open();
	return 0;
}