#pragma once
#include "../Object/GameObject/GameObject.h"
#include "../Event/Delegate/Delegate.h"
#include <string>
//Propriété et caractéristique des entités

class Window;

class Entity :public GameObject
{
#pragma region f/p
protected:
	std::string name = "name";
	float life = 100.0f;
	bool isDead = false;
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	float attack = 50.0f;
	int level = 1;
	float positionX = 100.0f;
	float positionY = 100.0f;
public:
	Delegate<void> OnDie = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Entity() = default;
	virtual ~Entity() = default;
#pragma endregion constructor/destructor
#pragma region setter/Getter
public:
	float GetLife() const;
	float SetLife(const float _life);
	float GetAttack() const;
	float SetAttack(const float _attack);
	int SetLevel(const int _level);
	int GetLevel() const;
#pragma endregion setter/Getter
#pragma region methods
public:
	virtual void Die() =0;
	virtual void Restart() = 0;
	virtual void IsHit(const float _dammage);
	virtual void Init() = 0;
	virtual void SetPosition(sf::Vector2f _position);
	virtual sf::Drawable* GetDrawable() = 0;
#pragma endregion methods
#pragma region override
	void OnUpdate() override =0;
	virtual sf::FloatRect GetGlobalBounds()const override =0;
	virtual sf::Vector2f Position()const override =0;
#pragma endregion override
};

