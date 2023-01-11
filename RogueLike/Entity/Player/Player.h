#pragma once
#include "../Entity.h"
class Player : public Entity
{
	std::string name = "";
public:
	Player(std::string _name);
};

