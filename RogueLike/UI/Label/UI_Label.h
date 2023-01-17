#pragma once
#include "../UI_Element.h"

class UI_Label : public UI_Element
{
#pragma region f/p
private:
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	UI_Label() = default;
	UI_Label(Window* _owner, const char* _text);
	//To initialize the label with a different font.
	UI_Label(Window* _owner, const char* _text, const char* _path);
	UI_Label(const UI_Label& _copy);
	virtual ~UI_Label() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Free();
public:
	void SetCharacterSize(const int _size);
	void SetColor(const sf::Color& _color);
	void SetText(const char* _text);
	void SetText(const std::string& _text);
#pragma endregion methods
#pragma region override
public:
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual sf::FloatRect GetGlobalBounds() override;
#pragma endregion override
};