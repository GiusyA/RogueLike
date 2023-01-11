#pragma once
#include <string>
#include <vector>

class Item;
class Player;
class Entity;

class Inventory
{
#pragma region f/p
private:
	std::string name = "Inventory of ...";
	std::vector<Item*> items = std::vector<Item*>();
	Player* owner = nullptr;
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
	/// Find item in 
	/// </summary>
	/// <param name="_item"></param>
	/// <returns></returns>
	size_t FindItem(Item* _item);
public:
	/// <summary>
	/// Use item in inventory
	/// </summary>
	/// <param name="_item">Item*</param>
	void UseItem(Item* _item, Entity* _entity);
	/// <summary>
	/// Add item in inventory and return true of false if can add an item
	/// </summary>
	/// <param name="_item">Item*</param>
	/// <returns>Boolean</returns>
	bool AddItem(Item* _item);
	/// <summary>
	/// Remove an item from inventory and return true of false if can remove an item
	/// </summary>
	/// <param name="_item">Item*</param>
	/// <returns>Boolean</returns>
	bool RemoveItem(Item* _item);
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
#pragma endregion methods
};

