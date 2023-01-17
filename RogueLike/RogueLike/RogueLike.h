#pragma once
#include "../Window/Window.h"

class RogueLike : public Window
{
#pragma region f/p
private:
	bool onMain = true;
	bool onMap = false;
	bool onDung = false;
	class Player* player = nullptr;
	class Inventory* inventory = nullptr;
	class Monster* monster = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RogueLike();
	~RogueLike() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Close();
	void EnterShop();
	void EnterDungeon();
	void LaunchNewGame();
#pragma region Dung
	void UpdateHealPotion();
	void UpdateManaPotion();
	void UpdatePotions();
	void UpdateSpells();
#pragma endregion Dung
#pragma region Map
	void DestroyMapDoor();
#pragma endregion Map
#pragma endregion methods
#pragma region override
public:
	virtual void InitMenus() override;
	virtual void OnDraw() override;
	virtual void OnReceiveEvent(const sf::Event& _event) override;
	virtual void OnUpdate() override;
#pragma endregion override
};