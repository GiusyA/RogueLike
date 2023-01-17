#include "Player.h"
#include "../../Input/Input.h"
#include "../../UI/Image/UI_Image.h"
#include "../../Inventory/Inventory.h"
#include "../../Inventory/Item/Database/ItemDatabase.h"
#include "../../Inventory/Item/Item.h"
#include "../../RogueLike/Menu/DungeonMenu/RL_DungeonMenu.h"

#pragma region constructor/destructor
Player::Player(class Window* _owner, const sf::Vector2f& _position, const std::string& _name)
	: Entity(_owner, "../Assets/Heros/mage.png", _position, _name) {}

Player::~Player()
{
	Entity::~Entity();

	delete inventory;
	inventory = nullptr;
}
#pragma endregion constructor/destructor

#pragma region methods
void Player::AddLife(const float _life)
{
	life += _life;
	life = (life > 100) ? 100 : life;
}

void Player::AddMana(const float _mana)
{
	mana += _mana;
	mana = (mana > 100) ? 100 : mana;
}

void Player::RemoveMana(const float _mana)
{
	mana -= _mana;
	mana = (mana < 0) ? 0 : mana;
}

void Player::SetInventory(Inventory* _inventory)
{
	inventory = _inventory;
}

float Player::GetMana() const
{
	return mana;
}

Inventory* Player::GetInventory()
{
	return inventory;
}
#pragma endregion methods

#pragma region override
void Player::Init()
{
	Entity::Init();

	mana = 100.0f;
	inventory->Init();
}

void Player::OnCollisionEnter(GameObject* _other)
{

}

void Player::OnUpdate()
{
	Entity::OnUpdate();

	if (Input::IsKeyDown(sf::Keyboard::Q))
		image->SetPosition(sf::Vector2f(Position().x - 5, Position().y));

	if (Input::IsKeyDown(sf::Keyboard::D))
		image->SetPosition(sf::Vector2f(Position().x + 5, Position().y));

	if (isFighting)
	{
		if (Input::IsKeyDown(sf::Keyboard::F))
			inventory->Items()[inventory->FindItem(HEAL_POTION)]->OnUse(this);

		if (Input::IsKeyDown(sf::Keyboard::G))
			inventory->Items()[inventory->FindItem(MANA_POTION)]->OnUse(this);
	}
}
#pragma endregion override