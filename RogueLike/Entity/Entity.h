#pragma once
#pragma once
#include "../Object/GameObject/GameObject.h"
#include "../Event/Delegate/Delegate.h"

class Entity : public GameObject
{
#pragma region f/p
protected:
	bool isFighting = false;
	class UI_Image* image = nullptr;
	class Window* owner = nullptr;
	std::string name = "name";
	float life = 100.0f;
	float attack = 10.0f;
public:
	Delegate<void> OnDie = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Entity() = default;
	Entity(Window* _owner, const char* _path, const sf::Vector2f& _position, const std::string& _name);
	Entity(const Entity& _copy);
	virtual ~Entity() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void EntityMovementsLimits();
public:
	void IsHit(const float _dammage);
	void SetAttack(const float _attack);
	void SetIsFighting(const bool _value);
	void SetLife(const float _life);
	void SetPosition(const sf::Vector2f& _position);
	std::string GetName() const;
	float GetAttack() const;
	float GetLife() const;
	virtual void Init();
#pragma endregion methods
#pragma region override
public:
	virtual void OnCollisionEnter(GameObject* _other) override;
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
#pragma endregion override
};