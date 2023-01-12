#pragma once
#include "../Item.h"
class Weapons : public Item
{
#pragma region f/p
private:
	float damage = 0.0f;
	int cost = 0;
	std::string name = "";
#pragma endregion f/p

#pragma region constructor
public:
	Weapons() = default;
	Weapons(const std::string _texture, const std::string& _name, const float _damage, const float _cost);
	Weapons(const Weapons& _copy);
	~Weapons();
#pragma endregion constructor

#pragma region methods
public:
	float Cost() const;
	float Damage() const;
	void OnUse(class Player* _player) override;
	bool Equals(const Item* _other) const override;
	virtual std::string ToString() const override;
#pragma endregion methods
};

