#include "UI_ButtonLabel.h"
#include "../../Label/UI_Label.h"
#include "../../../Window/Window.h"

#pragma region constructor/destructor
UI_ButtonLabel::UI_ButtonLabel(Window* _owner, const char* _text) : UI_Element(_owner)
{
    label = new UI_Label(_owner, _text);
}

UI_ButtonLabel::UI_ButtonLabel(Window* _owner, const char* _text, const char* _path) : UI_Element(_owner)
{
    label = new UI_Label(_owner, _text, _path);
}

UI_ButtonLabel::UI_ButtonLabel(const UI_ButtonLabel& _copy)
{
    label = _copy.label;
}

UI_ButtonLabel::~UI_ButtonLabel()
{
    delete label;
    label = nullptr;

    OnClick = nullptr;
}
#pragma endregion constructor/destructor

#pragma region methods
void UI_ButtonLabel::SetCharacterSize(const int _size)
{
    label->SetCharacterSize(_size);
}

void UI_ButtonLabel::SetColor(const sf::Color& _color)
{
    label->SetColor(_color);
}

void UI_ButtonLabel::SetText(const char* _text)
{
    label->SetText(_text);
}
#pragma endregion methods

#pragma region override
void UI_ButtonLabel::Draw(Window* _window)
{
    label->Draw(_window);
}

void UI_ButtonLabel::OnUpdate()
{
    if (!isActive)
        return;

    const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && label->GetGlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
    {
        OnClick.Invoke();
    }
}

void UI_ButtonLabel::SetOrigin(const sf::Vector2f& _origin)
{
    label->SetOrigin(_origin);
}

void UI_ButtonLabel::SetPosition(const sf::Vector2f& _position)
{
    label->SetPosition(_position);
}

void UI_ButtonLabel::SetScale(const sf::Vector2f& _scale)
{
    label->SetScale(_scale);
}

sf::FloatRect UI_ButtonLabel::GetGlobalBounds()
{
    return label->GetGlobalBounds();
}
#pragma endregion 