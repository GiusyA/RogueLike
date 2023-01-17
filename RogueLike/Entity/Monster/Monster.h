#pragma once
#include "../Entity.h"

class Monster : public Entity
{
#pragma region constructor/destructor
public:
	Monster() = default;
	Monster(class Window* _owner, const sf::Vector2f& _position, const std::string& _name);
#pragma endregion constructor/destructor
#pragma region override
public:
	void OnUpdate() override;
#pragma endregion override
};