#pragma once
#include "../UI_Element.h"
#include "../../Event/Delegate/Delegate.h"

class UI_Button : public UI_Element
{
#pragma region f/p
private:
	class UI_Image* image = nullptr;
public:
	Delegate<void> OnClick = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	UI_Button() = default;
	UI_Button(Window* _owner, const char* _path);
	UI_Button(const UI_Button& _copy);
	virtual ~UI_Button() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
#pragma endregion methods
#pragma region override
public:
	virtual void Draw(Window* _window) override;
	virtual void OnUpdate() override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual sf::FloatRect GetGlobalBounds() override;
#pragma endregion 
};