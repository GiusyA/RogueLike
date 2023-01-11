#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

class UI_Element : public Object
{
#pragma region f/p
protected:
	bool isActive = false;
	class Window* owner = nullptr;
#pragma endregion f/p
#pragma region constructor
public:
	UI_Element() = default;
	UI_Element(Window* _owner);
	UI_Element(const UI_Element& _copy);
	~UI_Element() override;
#pragma endregion constructor
#pragma region methods
public:
	void SetActive(const bool _status);
	virtual void Draw(Window* _window) = 0;
	virtual void OnUpdate();
	virtual void SetOrigin(const sf::Vector2f& _origin) = 0;
	virtual void SetPosition(const sf::Vector2f& _position) = 0;
	virtual void SetScale(const sf::Vector2f& _scale) = 0;
	virtual sf::FloatRect GetGlobalBounds() = 0;
#pragma endregion methods
};