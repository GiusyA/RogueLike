#include "Player.h"
#include "../../Input/Input.h"
#include "../../UI/Image/UI_Image.h"

#pragma region constructor/destructor
Player::Player(class Window* _owner, const sf::Vector2f& _position) : Entity(_owner, "../Assets/Heros/mage.png", _position) {}
#pragma endregion constructor/destructor

#pragma region override
void Player::OnCollisionEnter(GameObject* _other)
{
}

void Player::OnUpdate()
{
	Entity::OnUpdate();

	if (Input::IsKeyDown(sf::Keyboard::Q))
		image->SetPosition(sf::Vector2f(Position().x - 5, Position().y));

	if (Input::IsKeyDown(sf::Keyboard::D))
		image->SetPosition(sf::Vector2f(Position().x + 5, Position().y));
}
#pragma endregion override