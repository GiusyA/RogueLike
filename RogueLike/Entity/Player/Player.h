#pragma once
#include "../Entity.h"

class Player : public Entity
{
#pragma region f/p
private:
	class Inventory* inventory = nullptr;
	float mana = 100.0f;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Player() = default;
	Player(class Window* _owner, const sf::Vector2f& _position, const std::string& _name);
	~Player() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void AddLife(const float _life);
	void AddMana(const float _mana);
	void RemoveMana(const float _mana);
	void SetInventory(Inventory* _inventory);
	float GetMana() const;
	Inventory* GetInventory();
#pragma endregion methods
#pragma region override
public:
	virtual void Init() override;
	virtual void OnCollisionEnter(GameObject* _other) override;
	virtual void OnUpdate() override;
#pragma endregion override
};