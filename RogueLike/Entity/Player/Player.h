#pragma once
#include "../Entity.h"
#include "../../Event/Delegate/Delegate.h"

class Inventory;
class Fireball;

class Player :public Entity
{
#pragma region f/p
private:
	Fireball* fireball = nullptr;
	Inventory* inventory = nullptr;
	float mana = 100.0f;
	bool isGameOver = false;
	std::vector<Fireball*> fire = std::vector<Fireball*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Player();
	virtual ~Player() override;
#pragma endregion constructor/destructor
#pragma region setter/getter
public:
	float GetMana() const;
	float SetMana(const float _mana);
	Inventory* GetInventory();
	void SetInventory(Inventory* _inventory);
#pragma endregion setter/getter
#pragma region methods
public:
	bool IsGameOver();
	void Action();
#pragma endregion methods
#pragma region override
public:
	virtual sf::Drawable* GetDrawable() override;
	virtual void Die() override;
	virtual void Restart() override;
	void OnUpdate() override;
	virtual void Init() override;
	virtual sf::FloatRect GetGlobalBounds()const override;
	virtual sf::Vector2f Position()const override;
	virtual void Collition() override;
	virtual void Attack() override;
	virtual void IsHit(const float _dammage) override;
	virtual sf::Drawable* GetDrawableProjectile() override;
#pragma endregion override
};

