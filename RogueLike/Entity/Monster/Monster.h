#pragma once
#include "../Entity.h"

class Player;
class Fireball;

class Monster : public Entity
{
#pragma region f/p
private:
	Player* player = nullptr;
	Fireball* fireball = nullptr;
	float speed = 0.5f;
	float delay = 0.0f;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Monster();
	virtual ~Monster() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Delay();
#pragma endregion methods
#pragma region override
public:
	virtual sf::Drawable* GetDrawable() override;
	virtual void Die() override;
	virtual void Restart() override;
	void OnUpdate() override;
	virtual void Init() override;
	virtual sf::FloatRect GetGlobalBounds()const override;
	virtual sf::Vector2f Position()const override;
	virtual void Collition() override;
	virtual void Attack() override;
	virtual void IsHit(const float _dammage) override;
	virtual sf::Drawable* GetDrawableProjectile() override;
#pragma endregion override
};

