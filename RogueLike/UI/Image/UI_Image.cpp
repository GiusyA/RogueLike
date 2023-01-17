#include "UI_Image.h"
#include "../../Window/Window.h"
#include "TextureManager/TextureManager.h"

#pragma region constructor/destructor
UI_Image::UI_Image(Window* _owner, const char* _path)
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();

	if (!texture->loadFromFile(_path))
	{
		Free();
		return;
	}

	sprite->setTexture(*texture);
}

UI_Image::UI_Image(const UI_Image& _copy)
{
	sprite = _copy.sprite;
	texture = _copy.texture;
}

UI_Image::~UI_Image()
{
	Free();
}
#pragma endregion constructor/destructor

#pragma region methods
void UI_Image::Free()
{
	delete sprite;
	sprite = nullptr;

	delete texture;
	texture = nullptr;
}

void UI_Image::SetTexture(const char* _path)
{
	delete texture;
	texture = new sf::Texture();

	if (!texture->loadFromFile(_path))
	{
		Free();
		return;
	}

	sprite->setTexture(*texture);
}

sf::Sprite* UI_Image::GetSprite()
{
	return sprite;
}
#pragma endregion methods

#pragma region override
void UI_Image::Draw(Window* _window)
{
	if (sprite != nullptr)
		_window->Draw(sprite);
}

void UI_Image::SetOrigin(const sf::Vector2f& _origin)
{
	sprite->setOrigin(_origin);
}

void UI_Image::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);
}

void UI_Image::SetScale(const sf::Vector2f& _scale)
{
	sprite->setScale(_scale);
}

sf::FloatRect UI_Image::GetGlobalBounds()
{
	return sprite->getGlobalBounds();
}
#pragma endregion override