#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../../UI/UI_Element.h"
#include "Database/ItemDatabase.h"

class Entity;
class UI_Image;

class Item : public UI_Element
{
#pragma region f/p
private:
	bool stackable = false;
	std::string name = "";
	int stack = 1;
	int maxStack = 64;
	int cost = 0;
	sf::Texture* texture = nullptr;
	sf::Sprite* sprite = nullptr;
#pragma endregion f/p

#pragma region constructor
public:
	Item() = default;
	/// <summary>
	/// Constructor for create an item with name, stackable, number of item, and max stack
	/// </summary>
	/// <param name="_name">string</param>
	/// <param name="stackable">boolean</param>
	/// <param name="_stack">int</param>
	/// <param name="_maxStack">int</param>
	Item(const std::string& _pathTexture, const std::string& _name, const bool& _stackable, const int& _cost, int _stack = 1, int _maxStack = 64);
	/// <summary>
	/// Constructor for create an item with name, stackable, and max stack (number of item is 1)
	/// </summary>
	/// <param name="_name">string</param>
	/// <param name="_maxStack">int</param>
	Item(const std::string& _pathTexture, const std::string& _name, const int& _maxStack, const int& _cost);
	/// <summary>
	/// Create item with just a name and can't be stackable
	/// </summary>
	/// <param name="_name">string</param>
	Item(const std::string& _pathTexture, const std::string& _name, const int& _cost);
	/// <summary>
	/// Constructor by copy
	/// </summary>
	/// <param name="_copy"></param>
	Item(const Item& _copy);
#pragma endregion constructor

#pragma region methods
public:
	/// <summary>
	/// Return name of item
	/// </summary>
	/// <returns>string</returns>
	std::string GetName() const;
	/// <summary>
	/// Return if item can be stackable
	/// </summary>
	/// <returns>bool</returns>
	bool IsStackable() const;
	/// <summary>
	/// Return number of stack
	/// </summary>
	/// <returns>int</returns>
	int Stack() const;
	/// <summary>
	/// Return number of max stack of item
	/// </summary>
	/// <returns>int</returns>
	int MaxStack() const;
	/// <summary>
	/// Set if item can be stackable
	/// </summary>
	/// <param name="_stackable">boolean</param>
	void SetIsStacklable(const bool& _stackable);
	/// <summary>
	/// Add an amount of item in stack
	/// </summary>
	/// <param name="_amount">int</param>
	void AddStack(const int& _amount);
	/// <summary>
	/// Set the stack of item
	/// </summary>
	/// <param name="_amount">int</param>
	void SetStack(const int& _amount);
	/// <summary>
	/// Remove a amount of item in stack
	/// </summary>
	/// <param name="_amount">int</param>
	void RemoveStack(const int& _amount);
	/// <summary>
	/// Set the max stack at amount
	/// </summary>
	/// <param name="_amount">int</param>
	void SetMaxStack(const int& _amount);
	/// <summary>
	/// Return sprite of item for showing in screen
	/// </summary>
	/// <returns>Sprite*</returns>
	sf::Sprite* GetSprite();

	/// <summary>
	/// Get cost of item
	/// </summary>
	/// <returns>int</returns>
	int GetCost() const;

	/// <summary>
	/// Use the item on an entity
	/// </summary>
	/// <param name="_entity">Entity*</param>
	virtual void OnUse(Entity* _entity);
	/// <summary>
	/// Use item on entity from player
	/// </summary>
	/// <param name="_player">Player*</param>
	/// <param name="_entity">Entity*</param>
	virtual void OnUse(class Player* _player);
	/// <summary>
	/// Get the information of item in string (use to display hover info for item in inventory)
	/// </summary>
	/// <returns>string</returns>
	virtual std::string ToString() const;
	/// <summary>
	/// Check if item in params is equals at this item
	/// </summary>
	/// <param name="_item">Item*</param>
	/// <returns>boolean</returns>
	virtual bool Equals(const Item* _item) const;

#pragma endregion methods


	// Inherited via UI_Element
	virtual void Draw(Window* _window) override;

	virtual void SetOrigin(const sf::Vector2f& _origin) override;

	virtual void SetPosition(const sf::Vector2f& _position) override;

	virtual void SetScale(const sf::Vector2f& _scale) override;

	virtual sf::FloatRect GetGlobalBounds() override;

};

