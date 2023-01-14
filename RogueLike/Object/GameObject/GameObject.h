#pragma once
#include "../Object.h"
#include <SFML/Graphics.hpp>

//Dessiner les object du jeu
class GameObject : public Object
{
#pragma region f/p
private:
	sf::Drawable* drawable = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	GameObject();
	GameObject(const GameObject& _copy);
	~GameObject() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual void OnCollisionEnter(GameObject* _other);
	virtual void OnDraw(class Window* _window);
	virtual void OnUpdate();
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	virtual sf::Vector2f Position() const = 0;
#pragma endregion methods
};