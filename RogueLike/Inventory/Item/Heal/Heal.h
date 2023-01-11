#pragma once
#include "../Item.h"
class Heal :  public Item
{
#pragma region f/p
private:
	float heal = 20.0f;
#pragma endregion f/p

#pragma region constructor
public:
	Heal() = default;
	Heal(std::string _name, int _amount = 1);
#pragma endregion constructor

#pragma region methods
	virtual void OnUse(Entity* _entity) override;
	virtual std::string ToString() const override;
#pragma endregion methods
};

