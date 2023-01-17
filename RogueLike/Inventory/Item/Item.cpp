#include "Item.h"
#include "../../Entity/Entity.h"
#include "../../UI/Image/UI_Image.h"
#include "../../Window/Window.h"
#pragma region constructor
Item::Item(const std::string&  _pathTexture, const std::string&  _name, const bool&  _stackable, const int& _cost, int _stack, int _maxStack) 
	
{
	name = _name;
	stackable = _stackable;
	stack = _stack;
	maxStack = _maxStack;
	cost = _cost;


	sprite = new sf::Sprite();
	texture = new sf::Texture();
	sprite->setPosition(0, 0);
	if (texture->loadFromFile(_pathTexture)) 
		sprite->setTexture(*texture);	
}

Item::Item(const std::string& _pathTexture, const std::string& _name, const int& _maxStack, const int& _cost)
	:Item(_pathTexture, _name, true, _cost ,1, _maxStack) { }


Item::Item(const std::string& _pathTexture, const std::string& _name, const int& _cost) :
	Item(_pathTexture, _name, false, _cost, 1, 1) { }

Item::Item(const Item& _copy)
{
	name = _copy.name;
	stackable = _copy.stackable;
	stack = _copy.stack;
	maxStack = _copy.maxStack;
	cost = _copy.cost;
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

void Item::SetIsStacklable(const bool& _stackable)
{
	stackable = _stackable;
}

void Item::AddStack(const int& _amount)
{
	int _newStack = stack + _amount;
	if (_amount < 0) return;
	if (_newStack > 64)
		stack = maxStack;
	else stack = _newStack;
}

void Item::SetStack(const int& _amount)
{
	stack = _amount;
}

void Item::RemoveStack(const int& _amount)
{
	int _newStack = stack - _amount;
	if (_amount < 0) return;
	if (_newStack < 0)
		stack = 0;
	else stack = _newStack;
}

void Item::SetMaxStack(const int& _amount)
{
	maxStack = _amount;
}

sf::Sprite* Item::GetSprite()
{
	return sprite;
}

int Item::GetCost() const
{
	return cost;
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

void Item::Draw(Window* _window)
{
	_window->Draw(sprite);
}

void Item::SetOrigin(const sf::Vector2f& _origin)
{
	sprite->setOrigin(_origin);
}

void Item::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);
}

void Item::SetScale(const sf::Vector2f& _scale)
{
	sprite->setScale(_scale);
}

sf::FloatRect Item::GetGlobalBounds()
{
	return sprite->getGlobalBounds();
}


#pragma endregion methods