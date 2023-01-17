#include "RogueLike.h"
#include "../Object/GameObject/Manager/GameObjectManager.h"
#include "Menu/DataBase/RL_DataBase.h"
#include "../UI/Button/UI_Button.h"
#include "../UI/Button/Label/UI_ButtonLabel.h"
#include "../UI/Label/UI_Label.h"
#include "../UI/Image/UI_Image.h"
#include "Door/RL_Door.h"
#include "../Entity/Player/Player.h"
#include "../Entity/Monster/Monster.h"
#include "../Inventory/Inventory.h"
#include "../Input/Input.h"
#include "../Inventory/Item/Database/ItemDatabase.h"
#include <iostream>

#pragma region constructor/destructor
//sf::Style::Close -> Can't resize.
RogueLike::RogueLike() : Window(600, 600, "Rogue Like", sf::Style::Close)
{
}

RogueLike::~RogueLike()
{
	delete inventory;
	inventory = nullptr;
}
#pragma endregion constructor/destructor

#pragma region methods
void RogueLike::Close()
{
	Window::Close();
}

void RogueLike::EnterShop()
{
	DestroyMapDoor();
	CloseAllMenus();
	sf::Vector2f _position((width / 2) - 25, (height / 2) + 20);
	player->SetPosition(_position);
}

void RogueLike::EnterDungeon()
{
	DestroyMapDoor();
	CloseAllMenus();
	onMap = false;
	onDung = true;

	sf::Vector2f _position((width / 2) - 25, height - player->GetGlobalBounds().height - 125);
	player->SetPosition(_position);

	monster = new Monster(this, sf::Vector2f(this->Width() / 2, this->Height() / 2), "Ghost");

	OpenMenu(DUNGEON_MENU);
}

void RogueLike::LaunchNewGame()
{
	CloseAllMenus();
	onMain = false;
	onMap = true;

	sf::Vector2f _position((width / 2) + 50, (height / 2) + 20);
	player = new Player(this, _position, "Nom");
	inventory = new Inventory(this, player->GetName());
	player->SetInventory(inventory);

	dynamic_cast<RL_MapMenu*>(menus[MAP_MENU])->ShopDoor()->SetCurrentPlayer(player);
	dynamic_cast<RL_MapMenu*>(menus[MAP_MENU])->DungeonDoor()->SetCurrentPlayer(player);

	OpenMenu(MAP_MENU);
}

void RogueLike::UpdateHealPotion()
{
	if (inventory->Items()[inventory->FindItem(HEAL_POTION)]->Stack() > 0)
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->HealPotion()->SetTexture("../Assets/Potions/heal.png");
	else
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->HealPotion()->SetTexture("../Assets/Potions/healgrey.png");
}

void RogueLike::UpdateManaPotion()
{
	if (inventory->Items()[inventory->FindItem(MANA_POTION)]->Stack() > 0)
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->ManaPotion()->SetTexture("../Assets/Potions/mana.png");
	else
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->ManaPotion()->SetTexture("../Assets/Potions/managrey.png");
}

void RogueLike::UpdatePotions()
{
	UpdateHealPotion();
	UpdateManaPotion();
}

void RogueLike::UpdateSpells()
{
	if (inventory->Items()[inventory->FindItem(SHIELD)]->Stack() > 0)
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->Shield()->SetTexture("../Assets/Spells/shield.png");

	if (inventory->Items()[inventory->FindItem(GODHEAL)]->Stack() > 0)
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->GodHeal()->SetTexture("../Assets/Spells/godheal.png");
}

void RogueLike::DestroyMapDoor()
{
	dynamic_cast<RL_MapMenu*>(menus[MAP_MENU])->ShopDoor()->Destroy();
	dynamic_cast<RL_MapMenu*>(menus[MAP_MENU])->DungeonDoor()->Destroy();
}
#pragma endregion methods

#pragma region override
void RogueLike::InitMenus()
{
	RL_MainMenu* _mainMenu = new RL_MainMenu(this);
	_mainMenu->QuitButton()->OnClick.SetDynamic(this, &RogueLike::Close);
	_mainMenu->PlayButton()->OnClick.SetDynamic(this, &RogueLike::LaunchNewGame);
	_mainMenu->Open();
	RegisterMenu(MAIN_MENU, _mainMenu);

	RL_MapMenu* _mapMenu = new RL_MapMenu(this);
	_mapMenu->ShopDoor()->OnEnter.SetDynamic(this, &RogueLike::EnterShop);
	_mapMenu->DungeonDoor()->OnEnter.SetDynamic(this, &RogueLike::EnterDungeon);
	RegisterMenu(MAP_MENU, _mapMenu);

	RL_DungeonMenu* _dungeonMenu = new RL_DungeonMenu(this);
	RegisterMenu(DUNGEON_MENU, _dungeonMenu);
}

void RogueLike::OnDraw()
{
	for (std::pair<const char*, BaseMenu*> _pair : menus)
		_pair.second->Draw();

	if (onMain)
		return;

	GameObjectManager::Instance()->Draw(this);
}

void RogueLike::OnReceiveEvent(const sf::Event& _event)
{
	Window::OnReceiveEvent(_event);
}

void RogueLike::OnUpdate()
{
	if (!onMain)
	{
		try
		{
			GameObjectManager* _instance = GameObjectManager::Instance();
			_instance->CheckCollision();
			_instance->Update();
			_instance->DestroyAllRequests();
		}
		catch (const std::exception& _e)
		{
			std::cout << _e.what() << std::endl;
		}
	}

	if (onDung)
	{
		if (Input::IsKeyDown(sf::Keyboard::Enter))
		{
			player->SetIsFighting(true);
			monster->SetIsFighting(true);
			dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->LaunchFight()->SetText("");
		}

		const int _l = player->GetLife();
		const int _m = player->GetMana();
		const std::string _life = std::to_string(_l);
		const std::string _mana = std::to_string(_m);

		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->Life()->SetText(_life);
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->Mana()->SetText(_mana);

		/*UpdatePotions();
		UpdateSpells();*/
	}
	else
		dynamic_cast<RL_DungeonMenu*>(menus[DUNGEON_MENU])->LaunchFight()->SetText("Press ENTER to fight");
}
#pragma endregion override