#include "UI_Label.h"
#include "../../Window/Window.h"

#pragma region constructor/destructor
UI_Label::UI_Label(Window* _owner, const char* _text) : UI_Element(_owner)
{
	text = new sf::Text();
	text->setString(_text);

	font = new sf::Font();
	if (!font->loadFromFile("../Fonts/Roboto-Regular.ttf"))
	{
		Free();
		return;
	}

	text->setFont(*font);
}

UI_Label::UI_Label(const UI_Label& _copy)
{
	text = _copy.text;
	font = _copy.font;
}

UI_Label::~UI_Label()
{
	Free();
}
#pragma endregion constructor/destructor

#pragma region methods
void UI_Label::Free()
{
	delete text;
	text = nullptr;

	delete font;
	font = nullptr;
}

void UI_Label::SetCharacterSize(const int _size)
{
	text->setCharacterSize(_size);
}

void UI_Label::SetColor(const sf::Color& _color)
{
	text->setFillColor(_color);
}

void UI_Label::SetText(const char* _text)
{
	text->setString(_text);
}
#pragma endregion methods

#pragma region override
void UI_Label::Draw(Window* _window)
{
	if (text != nullptr)
		_window->Draw(text);
}

void UI_Label::SetOrigin(const sf::Vector2f& _origin)
{
	text->setOrigin(_origin);
}

void UI_Label::SetPosition(const sf::Vector2f& _position)
{
	text->setPosition(_position);
}

void UI_Label::SetScale(const sf::Vector2f& _scale)
{
	text->setScale(_scale);
}

sf::FloatRect UI_Label::GetGlobalBounds()
{
	return text->getGlobalBounds();
}
#pragma endregion override