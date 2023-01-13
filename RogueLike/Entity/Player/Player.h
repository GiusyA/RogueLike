#pragma once
#include "../Entity.h"

class Player : public Entity
{
#pragma region constructor/destructor
public:
	Player() = default;
	Player(class Window* _owner, const sf::Vector2f& _position);
#pragma endregion constructor/destructor
#pragma region override
public:
	virtual void OnCollisionEnter(GameObject* _other) override;
	virtual void OnUpdate() override;
#pragma endregion override
};