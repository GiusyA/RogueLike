#pragma once
#include <SFML/Graphics.hpp>

class Input
{
#pragma region methods
public:
	static bool IsKeyDown(const sf::Keyboard::Key& _key);
	static bool IsKeyUp(const sf::Keyboard::Key& _key);
#pragma endregion methods
};