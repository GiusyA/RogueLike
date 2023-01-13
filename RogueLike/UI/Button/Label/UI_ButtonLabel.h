#pragma once
#include "../../UI_Element.h"
#include "../../../Event/Delegate/Delegate.h"

class UI_ButtonLabel : public UI_Element
{
#pragma region f/p
private:
	class UI_Label* label = nullptr;
public:
	Delegate<void> OnClick = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	UI_ButtonLabel() = default;
	UI_ButtonLabel(Window* _owner, const char* _text);
	UI_ButtonLabel(Window* _owner, const char* _text, const char* _path);
	UI_ButtonLabel(const UI_ButtonLabel& _copy);
	virtual ~UI_ButtonLabel() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetCharacterSize(const int _size);
	void SetColor(const sf::Color& _color);
	void SetText(const char* _text);
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