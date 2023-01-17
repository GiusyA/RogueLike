#include "Inventory.h"
#include "../Entity/Entity.h"
#include "../Entity/Player/Player.h"
#include "Item/Item.h"
#include "Item/Spells/Spells.h"
#include "../UI/Label/UI_Label.h"
#include "../UI/Image/UI_Image.h"
#include "../Window/Window.h"
#pragma region constructor/destructor
Inventory::Inventory(Window* _owner, const std::string& _player)
{
	owner = _owner;
	name = "Inventory of " + _player;
	money = 0;
}

Inventory::Inventory(const Inventory& _copy)
{
	name = _copy.name;
	owner = _copy.owner;
	money = _copy.money;
	items = _copy.items;
}

Inventory::~Inventory()
{
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

size_t Inventory::FindItem(const char* _name)
{
	if (items.empty())
		return -1;

	size_t _size = items.size();

	for (size_t i = 0; i < _size; i++)
	{
		if (items[i]->GetName() == _name)
			return i;
	}
}

void Inventory::DisplayItem(Window* _owner, Item* _item, const int& _width, const int& _height)
{
	int _spaceBetween = 50;
	_item->GetSprite()->setPosition(sf::Vector2f(_width, _height));
	_item->GetSprite()->setScale(sf::Vector2f(1.5f, 1.5f));

	sf::Vector2f _position = _item->GetSprite()->getPosition();

	UI_Label _text = UI_Label(_owner, _item->GetName().c_str());
	_text.SetPosition(_position + sf::Vector2f(_item->GetGlobalBounds().width + _spaceBetween, 0));
	_text.SetScale(sf::Vector2f(.7f, .7f));

	std::string _amountStr = "x" + std::to_string(_item->Stack());
	UI_Label _amount = UI_Label(_owner, _amountStr.c_str());
	_amount.SetScale(sf::Vector2f(.7f, .7f));
	_amount.SetPosition(_position + sf::Vector2f(_item->GetGlobalBounds().width + _text.GetGlobalBounds().width + _spaceBetween * 2, 0));

	_owner->Draw(_item->GetSprite());
	_text.Draw(_owner);
	_amount.Draw(_owner);
}

void Inventory::DisplaySpell(Window* _owner, Spells* _spell, const int& _width, const int& _height)
{

	_spell->GetSprite()->setPosition(sf::Vector2f(_width, _height));

	sf::Vector2f _position = _spell->GetSprite()->getPosition();

	UI_Label _text = UI_Label(_owner, _spell->GetName().c_str());
	_text.SetPosition(_position + sf::Vector2f(0, _spell->GetGlobalBounds().height + 30) - sf::Vector2f((_spell->GetGlobalBounds().width / 2) + 10, 0));
	_text.SetScale(sf::Vector2f(.5f, .5f));

	_owner->Draw(_spell->GetSprite());
	_text.Draw(_owner);
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

void Inventory::AddItem(Item* _item, const int& _amount)
{
	size_t slot = FindItem(_item);
	if (slot == -1) {
		items.push_back(_item);
		if (_amount != 1)
			AddItem(_item, _amount - 1);
	}
	else {
		items[slot]->AddStack(_amount);
		return;
	}
}

void Inventory::RemoveItem(Item* _item, const int& _amount)
{
	size_t slot = FindItem(_item);
	if (slot == -1)
	{
		return;
	}
	else
	{
		items[slot]->RemoveStack(_amount);
		if (items[slot]->Stack() == 0)
			items.erase(items.begin() + slot);
	}
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
int Inventory::GetMoney() const
{
	return money;
}
void Inventory::AddMoney(const int& _money)
{
	money += _money;
}
void Inventory::RemoveMoney(const int& _money)
{
	int _newMoney = money - _money;
	if (_newMoney > 0)
		money = _newMoney;
	else
		money = 0;
}
void Inventory::SetMoney(const int& _money)
{
	money = _money;
}
void Inventory::DisplayMoney(Window* _owner, const int& _width, const int& _height)
{
	UI_Image logo = UI_Image(_owner, "../assets/money.png");
	logo.SetPosition(sf::Vector2f(_width, _height));
	logo.SetScale(sf::Vector2f(1.5f, 1.5f));
	UI_Label text = UI_Label(_owner, std::to_string(money).c_str());
	text.SetScale(sf::Vector2f(0.6f, 0.6f));
	text.SetPosition(sf::Vector2f(logo.GetSprite()->getPosition().x + logo.GetGlobalBounds().width + 10, _height));
	logo.Draw(_owner);
	text.Draw(_owner);
}

void Inventory::DisplayItems(Window* _owner, const int& _width, const int& _height, const int& _gap)
{
	int y = _height;
	int numberSpell = 1;
	size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		Item* _item = items[i];
		//TODO check if item is spell or not
		if (!dynamic_cast<Spells*>(items[i])) {
			sf::Sprite sprite = *_item->GetSprite();
			sf::Vector2f _position = sprite.getPosition();
			if (i != 0)
				y += sprite.getGlobalBounds().height + _gap;
			DisplayItem(_owner, _item, _width, y);
		}
	}
}
void Inventory::DisplaySpells(Window* _owner, const int& _width, const int& _heigth, const int& _gap)
{
	UI_Label _title = UI_Label(_owner, "Spells");
	int _w = ((_owner->Width() / 2) / 2) - (_title.GetGlobalBounds().width / 2);
	_title.SetPosition(sf::Vector2f(_w, _heigth - 50));
	_title.SetCharacterSize(20);
	_title.Draw(_owner);

	int w = _width;
	size_t _size = items.size();
	int numberSpell = 0;
	for (size_t i = 0; i < _size; i++)
	{
		Item* _item = items[i];
		//TODO check if item is spell or not
		if (dynamic_cast<Spells*>(items[i])) {
			Spells* _spell = dynamic_cast<Spells*>(items[i]);
			sf::Sprite sprite = *_item->GetSprite();
			sf::Vector2f _position = sprite.getPosition();
			_item->GetSprite()->setScale(sf::Vector2f(2.0f, 2.0f));
			if (numberSpell != 0)
				w += sprite.getGlobalBounds().width + _gap;
			DisplaySpell(_owner, _spell, w, _heigth);
			numberSpell++;
		}
	}
}
void Inventory::DisplayPlayer(Window* _owner, const int& _width, const int& _heigth)
{
	UI_Image player = UI_Image(_owner, "../assets/player.png");
	player.SetPosition(sf::Vector2f(_width, _heigth));
	player.SetScale(sf::Vector2f(10.0f, 10.0f));
	player.Draw(_owner);
}

void Inventory::Init()
{
	money = 0;
	Clear();
}
#pragma endregion methods