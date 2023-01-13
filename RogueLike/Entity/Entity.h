#pragma once
#pragma once
#include "../Object/GameObject/GameObject.h"

class Entity : public GameObject
{
#pragma region f/p
protected:
	bool isDead = false;
	class UI_Image* image = nullptr;
	class Window* owner = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Entity() = default;
	Entity(Window* _owner, const char* _path, const sf::Vector2f& _position);
	Entity(const Entity& _copy);
	virtual ~Entity() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void EntityMovementsLimits();
public:
	void SetPosition(const sf::Vector2f& _position);
#pragma endregion methods
#pragma region override
public:
	virtual void OnCollisionEnter(GameObject* _other) override;
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
#pragma endregion override
};