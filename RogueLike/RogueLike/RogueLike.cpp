#include "RogueLike.h"
#include "../Object/GameObject/Manager/GameObjectManager.h"
#include "../UI/Button/UI_Button.h"
#include "../Entity/Player/Player.h"
#include "../Inventory/Inventory.h"
#include "Menu/ShopMenu/ShopMenu.h"
#include "Menu/GameOver/GameOverMenu.h"
#include "../Inventory/Item/Potion/Heal/HealPotion.h"
#include "../Inventory/Item/Potion/Mana/ManaPotion.h"
#include "../Inventory/Item/Spells/Fireball/Fireball.h"
#include "../Inventory/Item/Spells/GodHeal/GodHeal.h"
#include "../Inventory/Item/Spells/Shield/Shield.h"
#include "../Inventory/Item/Weapons/Sword/IronSword.h"
#include <iostream>

#pragma region constructor/destructor
//sf::Style::Close -> Can't resize.
RogueLike::RogueLike() : Window(600, 600, "Rogue Like")
{
	player = new Player(this, sf::Vector2f(0, 0));
	player->SetPosition(sf::Vector2f(
		(width / 2) - (player->GetGlobalBounds().width / 2),
		(height / 2) - (player->GetGlobalBounds().height / 2)));	
	RegisterItems();
}

void RogueLike::RegisterItems()
{
	GameObjectManager::Instance()->RegisterItem(new HealPotion(20, 50));
	GameObjectManager::Instance()->RegisterItem(new ManaPotion(20, 50));
	GameObjectManager::Instance()->RegisterItem(new Fireball(20, 150));
	GameObjectManager::Instance()->RegisterItem(new GodHeal(999, 500, player->GetMaxMana()));
	GameObjectManager::Instance()->RegisterItem(new IronSword(50, 100));
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

void RogueLike::Start()
{
	RegisterItems();
}

void RogueLike::GameOver()
{	
	GameObjectManager::Instance()->DestroyAllObjects();
}

void RogueLike::Exit()
{
	std::exit(0);
}

#pragma endregion methods

#pragma region override
void RogueLike::InitMenus()
{
	ShopMenu* _shopMenu = new ShopMenu(this);
	//_shopMenu->Open();
	RegisterMenu("shop", _shopMenu);
	
	GameOverMenu* _gameOver = new GameOverMenu(this);
	_gameOver->RestartButton()->OnClick.SetDynamic(this, &RogueLike::Start);
	_gameOver->QuitButton()->OnClick.SetDynamic(this, &RogueLike::Exit);
	_gameOver->Open();
	RegisterMenu("gameover", _gameOver);
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