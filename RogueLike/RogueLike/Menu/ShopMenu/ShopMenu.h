#pragma once
#include "../../../Window/Menu/BaseMenu.h"
#include "../../../Entity/Player/Player.h"
#include <vector>
#include <SFML/Graphics.hpp>

class ShopMenu : public BaseMenu
{
#pragma region f/p
private:
	class UI_Image* table1 = nullptr;
	UI_Image* table2 = nullptr;
	UI_Image* table3 = nullptr;
	UI_Image* background = nullptr;
	class UI_Label* inventory = nullptr;
	UI_Label* labelBuy = nullptr;

#pragma endregion f/p

#pragma region constructor
public:
	ShopMenu() = default;
	ShopMenu(Window* _owner);
	void InitLabel();
	virtual ~ShopMenu();
#pragma endregion constructor

private:
	void InitItems();
	void InitTables();
	void InitBackground();
};

