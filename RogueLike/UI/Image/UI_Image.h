#pragma once
#include "../UI_Element.h"

class UI_Image : public UI_Element
{
#pragma region f/p
private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	UI_Image() = default;
	UI_Image(Window* _owner, const char* _path);
	UI_Image(const UI_Image& _copy);
	virtual ~UI_Image() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Free();
public:
	sf::FloatRect GetGlobalBounds() const;
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