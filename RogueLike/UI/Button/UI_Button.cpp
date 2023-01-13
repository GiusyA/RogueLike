#include "UI_Button.h"
#include "../Image/UI_Image.h"
#include "../../Window/Window.h"

#pragma region constructor/destructor
UI_Button::UI_Button(Window* _owner, const char* _path) : UI_Element(_owner)
{
	image = new UI_Image(_owner, _path);
}
UI_Button::UI_Button(const UI_Button& _copy)
{
	image = _copy.image;
}

UI_Button::~UI_Button()
{
	delete image;
	image = nullptr;

	OnClick = nullptr;
}
#pragma endregion constructor/destructor

#pragma region methods
#pragma endregion methods

#pragma region override
void UI_Button::Draw(Window* _window)
{
	image->Draw(_window);
}

void UI_Button::OnUpdate()
{
	if (!isActive)
		return;

	const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && image->GetGlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
		OnClick.Invoke();
}

void UI_Button::SetOrigin(const sf::Vector2f& _origin)
{
	image->SetOrigin(_origin);
}

void UI_Button::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position);
}

void UI_Button::SetScale(const sf::Vector2f& _scale)
{
	image->SetScale(_scale);
}
sf::FloatRect UI_Button::GetGlobalBounds()
{
	return image->GetGlobalBounds();
}
#pragma endregion override