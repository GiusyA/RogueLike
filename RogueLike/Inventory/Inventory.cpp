#include "Inventory.h"
#include "../Entity/Entity.h"
#include "../Entity/Player/Player.h"
#include "Item/Item.h"
#include "Item/Spells/Spells.h"
#include "../UI/Label/UI_Label.h"
#include "../Window/Window.h"
#pragma region constructor/destructor
Inventory::Inventory(Player* _player)
{
	owner = _player;
	name = "Inventory of " + owner->GetName();
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
	int found = -1;
	if (items.empty())
		return found;
	size_t _size = items.size();
	for (size_t i = 0; i < _size; i++) 
	{
		if (items[i]->Equals(_item)) 
		{
			found = i;
			break;
		}
	}
	return found;
}

void Inventory::DisplayItem(Window* _owner, Item* _item, const int& _width, const int& _height)
{
	_item->GetSprite()->setPosition(sf::Vector2f(_width, _height));
	_item->GetSprite()->setScale(sf::Vector2f(1.5f, 1.5f));

	sf::Vector2f _position = _item->GetSprite()->getPosition();

	UI_Label _text = UI_Label(_owner, _item->GetName().c_str());
	_text.SetPosition(_position + sf::Vector2f(_item->GetGlobalBounds().width + 100, 0));
	_text.SetScale(sf::Vector2f(.7f, .7f));

	std::string _amountStr = "x" + std::to_string(_item->Stack());
	UI_Label _amount = UI_Label(_owner, _amountStr.c_str());
	_amount.SetScale(sf::Vector2f(.7f, .7f));
	_amount.SetPosition(_position + sf::Vector2f(_item->GetGlobalBounds().width + _text.GetGlobalBounds().width + 200, 0));
	
	_owner->Draw(_item->GetSprite());
	_text.Draw(_owner);
	_amount.Draw(_owner);
}

bool Inventory::HasSpells(Spells* _spells)
{
	return (FindItem((Item*)_spells)) != -1;
}

void Inventory::UseSpells(Spells* _spells, Player* _player)
{
	_spells->OnUse(_player);
}

void Inventory::UseItem(Item* _item, Entity* _entity)
{
	Item* _i = items[FindItem(_item)];
	if (_i == nullptr) return;
	_i->OnUse(_entity);
	if (_i->Stack() == 0)
		RemoveItem(_i);
}

bool Inventory::AddItem(Item* _item, const int& _amount)
{
	size_t slot = FindItem(_item);
	if (slot == -1) {
		items.push_back(_item);
		if(_amount != 1)
			AddItem(_item, _amount - 1);
		return true;
	}
	else {
		items[slot]->AddStack(_amount);
		return true;
	}
	return false;
}

bool Inventory::RemoveItem(Item* _item, const int& _amount)
{
	size_t slot = FindItem(_item);
	if (slot == -1) 
	{
		return false;
	}
	else 
	{
		items[slot]->RemoveStack(_amount);
		if (items[slot]->Stack() == 0)
			RemoveItem(items[slot]);
		return true;
	}
	return false;
}

void Inventory::Clear()
{
	size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
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
	for (size_t i = 0; i < _size; i++)
		count += items[i]->Stack();
	return count;
}

std::vector<Item*> Inventory::Items() const
{
	return items;
}
void Inventory::DisplayInventory(Window* _owner, const int& _width, const int& _height, const int& _gap)
{
	int y = _height;
	size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		Item* _item = items[i];
		//TODO check if item is spell or not		
		if (!dynamic_cast<Spells*>(items[i])) {
			sf::Sprite sprite = *_item->GetSprite();
			sf::Vector2f _position = sprite.getPosition();
			if(i != 0)
				y += sprite.getGlobalBounds().height + _gap;
			DisplayItem(_owner, _item, _width, y);
		}
	}
}
#pragma endregion methods