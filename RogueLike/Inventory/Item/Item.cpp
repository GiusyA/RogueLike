#include "Item.h"
#include "../../Entity/Entity.h"
#include "../../UI/Image/UI_Image.h"

#pragma region constructor
Item::Item(std::string _pathTexture, std::string _name, bool _stackable, int _stack, int _maxStack)
{
	name = _name;
	stackable = _stackable;
	stack = _stack;
	maxStack = _maxStack;

	sprite = new sf::Sprite();
	texture = new sf::Texture();
	sprite->setPosition(0, 0);
	if (texture->loadFromFile(_pathTexture)) {
		sprite->setTexture(*texture);
		drawable = sprite;
	}
}

Item::Item(std::string _pathTexture, std::string _name, int _maxStack) :
	Item(_pathTexture, _name, true, 1, _maxStack) { }


Item::Item(std::string _pathTexture, std::string _name) : Item(_pathTexture, _name, false, 1, 1) { }

Item::Item(const Item& _copy)
{
	name = _copy.name;
	stackable = _copy.stackable;
	stack = _copy.stack;
	maxStack = _copy.maxStack;
}
#pragma endregion constructor

#pragma region methods
std::string Item::GetName() const
{
	return name;
}
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

sf::Sprite* Item::GetSprite()
{
	return sprite;
}

void Item::OnUse(Entity* _entity)
{
	RemoveStack(1);
}

void Item::OnUse(Player* _player)
{

}

std::string Item::ToString() const
{
	return "";
}


bool Item::Equals(const Item* _item) const
{
	return name == _item->name;
}
sf::FloatRect Item::GetGlobalBounds() const
{
	return sf::FloatRect();
}
sf::Vector2f Item::Position() const
{
	return sf::Vector2f();
}
#pragma endregion methods