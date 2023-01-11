#include "Inventory.h"
#include "../Entity/Entity.h"
#include "../Entity/Player/Player.h"
#include "Item/Item.h"
#pragma region constructor/destructor
Inventory::Inventory(Player* _player)
{
	name = "Inventory of " + _player->GetName();
	owner = _player;
}

Inventory::Inventory(const Inventory& _copy)
{
	name = _copy.name;
	owner = _copy.owner;
}

Inventory::~Inventory()
{
	delete owner;
	Clear();
}
#pragma endregion constructor/destructor

#pragma region methods
size_t Inventory::FindItem(Item* _item)
{
	size_t _size = items.size();
	for (int i = 0; i < _size; i++)
		if (items[i] == _item)
			return i;
	return -1;
}

void Inventory::UseItem(Item* _item, Entity* _entity)
{
	Item* _i = items[FindItem(_item)];
	if (_i == nullptr) return;
	_i->OnUse(_entity);
	if (_i->Stack() == 0)
		RemoveItem(_i);
}

bool Inventory::AddItem(Item* _item)
{
	size_t slot = FindItem(_item);
	if (slot == -1) {
		items.push_back(_item);
		return true;
	}
	else {
		items[slot]->AddStack(1);
		return true;
	}
	return false;
}

bool Inventory::RemoveItem(Item* _item)
{
	size_t slot = FindItem(_item);
	if (slot == -1) 
	{
		return false;
	}
	else 
	{
		items[slot]->RemoveStack(1);
		return true;
	}
	return false;
}

void Inventory::Clear()
{
	size_t _size = items.size();
	for (int i = 0; i < _size; i++)
	{
		delete items[i];
	}
	items.clear();
}

int Inventory::SizeInventory() const
{
	return items.size();
}

int Inventory::CountItems() const
{
	size_t _size = items.size();
	int count = 0;
	for (int i = 0; i < _size; i++)
		count += items[i]->Stack();
	return count;
}

std::vector<Item*> Inventory::Items() const
{
	return items;
}
#pragma endregion methods