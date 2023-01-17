#pragma once
#include <string>
#include <vector>

class Item;
class Player;
class Entity;
class Window;
class Spells;

class Inventory
{
#pragma region f/p
private:
	std::string name = "Inventory of ...";
	Player* owner = nullptr;
	std::vector<Item*> items = std::vector<Item*>();
	int money = 0;
#pragma endregion f/p

#pragma region constructor/destructor
public:
	Inventory() = default;
	/// <summary>
	/// Constructor of inventory to create an inventory for the player
	/// </summary>
	/// <param name="_player">Player*</param>
	Inventory(Player* _entity);
	Inventory(const Inventory& _copy);
	~Inventory();
#pragma endregion constructor/destructor

#pragma region methods
private:
	/// <summary>
	/// Find item in inventory
	/// </summary>
	/// <param name="_item"></param>
	/// <returns></returns>
	size_t FindItem(Item* _item);

	/// <summary>
	/// Display item with graphics
	/// </summary>
	/// <param name="_item">Item*</param>
	void DisplayItem(Window* _owner, Item* _item, const int& _width, const int& _height);

	/// <summary>
	/// Display spells in slot
	/// </summary>
	/// <param name="_owner">Window*</param>
	/// <param name="_spell">Spells*</param>
	/// <param name="_width">int</param>
	/// <param name="_height">int</param>
	void DisplaySpell(Window* _owner, Spells* _spell, const int& _width, const int& _height);
public:
	/// <summary>
	/// Check if player has spells
	/// </summary>
	/// <param name="_spells">Spells*</param>
	/// <returns>boolean</returns>
	bool HasSpells(Spells* _spells);
	/// <summary>
	/// Use spells selected to entity
	/// </summary>
	/// <param name="_spells"></param>
	/// <param name="_entity"></param>
	void UseSpells(Spells* _spells, Player* _player);
	/// <summary>
	/// Use item in inventory
	/// </summary>
	/// <param name="_item">Item*</param>
	void UseItem(Item* _item, Entity* _entity);
	/// <summary>
	/// Add item in inventory and return true of false if can add an item
	/// </summary>
	/// <param name="_item">Item*</param>
	/// <param name="_amount">int</param>
	/// <returns>Boolean</returns>
	void AddItem(Item* _item, const int& _amount = 1);
	/// <summary>
	/// Remove an item from inventory and return true of false if can remove an item
	/// </summary>
	/// <param name="_item">Item*</param>
	/// <param name="_amount">int</param>
	/// <returns>Boolean</returns>
	void RemoveItem(Item* _item, const int& _amount = 1);
	/// <summary>
	/// Clear totally of inventory
	/// </summary>
	void Clear();
	/// <summary>
	/// Get size of inventory (not count of all items !)
	/// </summary>
	/// <returns>Integer</returns>
	int SizeInventory() const;
	/// <summary>
	/// Get all counts of items in inventory
	/// </summary>
	/// <returns>Integer</returns>
	int CountItems() const;
	/// <summary>
	/// Return a vector of all items in inventory
	/// </summary>
	/// <returns>Vector<Item*></returns>
	std::vector<Item*> Items() const;
	/// <summary>
	/// Get money of player
	/// </summary>
	/// <returns>int</returns>
	int GetMoney() const;
	/// <summary>
	/// Add money to player inventory
	/// </summary>
	/// <param name="_money">int</param>
	void AddMoney(const int& _money);
	/// <summary>
	/// Remove money from player inventory
	/// </summary>
	/// <param name="_money">int</param>
	void RemoveMoney(const int& _money);
	/// <summary>
	/// Set money of player
	/// </summary>
	/// <param name="_money">int</param>
	void SetMoney(const int& _money);
	/// <summary>
	/// Display money with graphics
	/// </summary>
	void DisplayMoney(Window* _owner, const int& _width, const int& _height);	
	/// <summary>
	/// Display all inventory with graphics
	/// </summary>
	/// <param name="_owner">Window*</param>
	/// <param name="_width">int</param>
	/// <param name="_height">int</param>
	/// <param name="_gap">int</param>
	void DisplayItems(Window* _owner, const int& _width, const int& _height, const int& _gap);
	/// <summary>
	/// Display all spells in graphics
	/// </summary>
	/// <param name="_owner">Window*</param>
	/// <param name="_width">int</param>
	/// <param name="_heigth">int</param>
	/// <param name="_gap">int</param>
	void DisplaySpells(Window* _owner, const int& _width, const int& _heigth, const int& _gap);

	/// <summary>
	/// Display player sprite 
	/// </summary>
	/// <param name="_owner">Window*</param>
	/// <param name="_width">int</param>
	/// <param name="_heigth">int</param>
	void DisplayPlayer(Window* _owner, const int& _width, const int& _heigth);
#pragma endregion methods
};

