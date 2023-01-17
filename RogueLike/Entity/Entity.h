#pragma once

#include "../Event/Delegate/Delegate.h"
#include "../Screen/Screen.h"
#include "../Object/ObjectShoot/ObjectShoot.h"
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
	bool isAttack = false;
	const float width = SCREEN_WIDTH;
	const float height = SCREEN_HEIGHT;
	const float collEntity = COLLENTITY;
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
	bool IsAttack();
#pragma endregion setter/Getter
#pragma region methods
public:
	virtual sf::Drawable* GetDrawableProjectile()=0;
	virtual void Die() =0;
	virtual void Restart() = 0;
	virtual void IsHit(const float _dammage) =0;
	virtual void Init() = 0;
	virtual sf::Drawable* GetDrawable() = 0;
	virtual void Collition() = 0;
	virtual void Attack() = 0;
#pragma endregion methods
#pragma region override
	void OnUpdate() override =0;
	virtual sf::FloatRect GetGlobalBounds()const override =0;
	virtual sf::Vector2f Position()const override =0;
#pragma endregion override
};

