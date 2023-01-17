#pragma once
#include "../../../Window/Menu/BaseMenu.h"

#define LAUNCH_FIGHT_TEXT "Press ENTER to fight"

class RL_DungeonMenu : public BaseMenu
{
#pragma region f/p
private:
	class UI_Image* background = nullptr;
	class UI_Label* launchFight = nullptr;
	UI_Label* money = nullptr;
	UI_Image* moneyImage = nullptr;
#pragma region potions
	UI_Label* healPotBind = nullptr;
	UI_Image* healPot = nullptr;
	UI_Label* manaPotBind = nullptr;
	UI_Image* manaPot = nullptr;
#pragma endregion potions
#pragma region spells
	UI_Label* fireballBind = nullptr;
	UI_Image* fireball = nullptr;
	UI_Label* shieldBind = nullptr;
	UI_Image* shield = nullptr;
	UI_Label* godHealBind = nullptr;
	UI_Image* godHeal = nullptr;
#pragma endregion spells
#pragma region vitals
	UI_Label* life = nullptr;
	UI_Image* lifeImage = nullptr;
	UI_Label* mana = nullptr;
	UI_Image* manaImage = nullptr;
#pragma endregion vitals
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RL_DungeonMenu() = default;
	RL_DungeonMenu(class Window* _owner);
	RL_DungeonMenu(const RL_DungeonMenu& _copy) = delete;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void InitBackground();
	void InitFireball();
	void InitGodheal();
	void InitHealPotion();
	void InitLaunchFightText();
	void InitLife();
	void InitMana();
	void InitManaPotion();
	void InitMoney();
	void InitPotions();
	void InitShield();
	void InitSpells();
public:
	UI_Label* LaunchFight();
	UI_Label* Life();
	UI_Label* Mana();
	UI_Label* Money();
	UI_Image* HealPotion();
	UI_Image* ManaPotion();
	UI_Image* Shield();
	UI_Image* GodHeal();
#pragma endregion methods
#pragma region override
public:
	virtual void Draw() override;
#pragma endregion override
};