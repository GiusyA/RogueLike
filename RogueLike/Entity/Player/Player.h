#pragma once
#include "../Entity.h"

class Inventory;

class Player :public Entity
{
#pragma region f/p
private:
	Inventory* inventory = nullptr;
	float mana = 100.0f;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Player() = default;
	Player(const std::string name, const float _life, UI_Image* _image, const float _attack, const int _level, const float _mana, const Inventory* _inventory);
	Player(const Player& _copy);
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
	void Init();
#pragma endregion methods
#pragma region override
public:
	virtual void OnDestroy(const bool _isdead) override;
#pragma endregion override

};

