#pragma once
#include "../Entity.h"
class Player : public Entity
{
	class Inventory* inv = nullptr;
public:
	Player(std::string _name);
	~Player();

	Inventory* GetInventory();
};

