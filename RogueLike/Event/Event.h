#pragma once
#include <SFML/Graphics.hpp>

class Event
{
#pragma region f/p
public:
	static inline sf::Event* currentEvent = nullptr;
#pragma endregion f/p
};