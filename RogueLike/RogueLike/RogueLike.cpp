#include "RogueLike.h"
#include "../Object/GameObject/Manager/GameObjectManager.h"
#include "Menu/DataBase/RL_DataBase.h"
#include "Menu/MainMenu/RL_MainMenu.h"
#include "Menu/MapMenu/RL_MapMenu.h"
#include "../UI/Button/UI_Button.h"
#include "../UI/Button/Label/UI_ButtonLabel.h"
#include "Door/RL_Door.h"
#include "../Entity/Player/Player.h"
#include "../Inventory/Inventory.h"
#include <iostream>

#pragma region constructor/destructor
//sf::Style::Close -> Can't resize.
RogueLike::RogueLike() : Window(600, 600, "Rogue Like", sf::Style::Close)
{
}

RogueLike::~RogueLike()
{
}
#pragma endregion constructor/destructor

#pragma region methods
void RogueLike::Close()
{
	Window::Close();
}

void RogueLike::EnterShop()
{
}

void RogueLike::EnterDungeon()
{
}

void RogueLike::LaunchNewGame()
{
	CloseAllMenus();
	onMain = false;
	onMap = true;
	sf::Vector2f _position((width / 2) + 50, (height / 2) + 20);
	player = new Player(this, _position);
	dynamic_cast<RL_MapMenu*>(menus[MAP_MENU])->ShopDoor()->SetCurrentPlayer(player);
	dynamic_cast<RL_MapMenu*>(menus[MAP_MENU])->DungeonDoor()->SetCurrentPlayer(player);
	OpenMenu(MAP_MENU);
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
}
#pragma endregion override