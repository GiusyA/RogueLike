#include "Item.h"
#include "../../Entity/Entity.h"

#pragma region constructor
Item::Item(std::string _name, bool _stackable, int _stack, int _maxStack)
{
	name = _name;
	stackable = _stackable;
	stack = _stack;
	maxStack = _maxStack;
}

Item::Item(std::string _name, int _maxStack) :
	Item(_name, true, 1, _maxStack) { }


Item::Item(std::string _name) : Item(_name, false, 1, 1) { }

Item::Item(const Item& _copy)
{
	name = _copy.name;
	stackable = _copy.stackable;
	stack = _copy.stack;
	maxStack = _copy.maxStack;
}
#pragma endregion constructor

#pragma region methods
bool Item::IsStackable() const
{
	return stackable;
}

int Item::Stack() const
{
	return stack;
}

int Item::MaxStack() const
{
	return maxStack;
}

void Item::SetIsStacklable(const bool _stackable)
{
	stackable = _stackable;
}

void Item::AddStack(const int _amount)
{
	int _newStack = stack + _amount;
	if (_amount < 0) return;
	if (_newStack > 64)
		stack = maxStack;
	else stack = _newStack;
}

void Item::SetStack(const int _amount)
{
	stack = _amount;
}

void Item::RemoveStack(const int _amount)
{
	int _newStack = stack - _amount;
	if (_amount < 0) return;
	if (_newStack < 0)
		stack = 0;
	else stack = _newStack;
}

void Item::SetMaxStack(const int _amount)
{
	maxStack = _amount;
}

void Item::OnUse(Entity* _entity)
{
	RemoveStack(1);
}


bool Item::Equals(Item* _item)
{
	return false;
}
#pragma endregion methods