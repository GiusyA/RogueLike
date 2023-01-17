#pragma once
#include "../GameObject/GameObject.h"

//Créer un object pour l'attack
class ObjectShoot :public GameObject
{
#pragma region f/p
private:
	bool isShot = false;
	bool isDestroy = false;
	sf::CircleShape *circle = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	ObjectShoot()=default;
	~ObjectShoot() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Move(const float _missileSpeed);
	void Shoot();
	void Destroy();
	bool IsShot();
	bool GetShot();
	bool IsDestroy();
	sf::CircleShape* ThisCircleShape();
#pragma endregion methods
#pragma region override
public:
	virtual void OnCollisionEnter(GameObject* _other) override;
	void SetPosition(sf::Vector2f _position);
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
#pragma endregion override
};

