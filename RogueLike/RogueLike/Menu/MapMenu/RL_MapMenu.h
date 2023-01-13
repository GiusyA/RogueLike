#pragma once
#include "../../../Window/Menu/BaseMenu.h"

class RL_MapMenu : public BaseMenu
{
#pragma region f/p
private:
	class UI_Label* inventory = nullptr;
	UI_Label* shopLabel = nullptr;
	UI_Label* dungeonLabel = nullptr;
	class RL_Door* shopDoor = nullptr;
	RL_Door* dungeonDoor = nullptr;
	class UI_Image* background = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor+
public:
	RL_MapMenu() = default;
	RL_MapMenu(class Window* _owner);
	RL_MapMenu(const RL_MapMenu& _copy) = delete;
	virtual ~RL_MapMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void InitBackground();
	void InitDungeonDoor();
	void InitDungeonLabel();
	void InitInventory();
	void InitShopDoor();
	void InitShopLabel();
public:
	RL_Door* ShopDoor();
	RL_Door* DungeonDoor();
#pragma endregion methods
#pragma region override
public:
	virtual void Draw() override;
#pragma endregion override
};