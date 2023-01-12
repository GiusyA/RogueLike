#pragma once
#include "../Item.h"
class Spells : public Item
{
#pragma region f/p
private:
	std::string name = "";
	float damage = 0.0f;
	float costMana = 0.0f;
#pragma endregion f/p

#pragma region constructor
public:
	Spells() = default;
	Spells(const std::string _texture, const std::string& _name, const float _damage, const float _cost);
	Spells(const Spells& _copy);
#pragma endregion constructor

#pragma region methods
public:
	float CostMana() const;
	float Damage() const;
	void OnUse(class Player* _player) override;
	bool Equals(const Item* _other) const override;
	virtual std::string ToString() const override;
#pragma endregion methods
};