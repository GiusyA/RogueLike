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
	bool AddItem(Item* _item, const int& _amount = 1);
	/// <summary>
	/// Remove an item from inventory and return true of false if can remove an item
	/// </summary>
	/// <param name="_item">Item*</param>
	/// <param name="_amount">int</param>
	/// <returns>Boolean</returns>
	bool RemoveItem(Item* _item, const int& _amount = 1);
	Item* GetItemAtSlot(const int& _slot);
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
	/// Display all inventory with graphics
	/// </summary>
	/// <param name="_owner">Window*</param>
	/// <param name="_width">int</param>
	/// <param name="_height">int</param>
	/// <param name="_gap">int</param>
	void DisplayInventory(Window* _owner, const int& _width, const int& _height, const int& _gap);
#pragma endregion methods
};

