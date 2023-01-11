#include "Input.h"
#include "../Event/Event.h"

#pragma region methods
bool Input::IsKeyDown(const sf::Keyboard::Key& _key)
{
    const sf::Event* _current = Event::currentEvent;

    if (_current == nullptr)
        return false;

    return _current->type == sf::Event::KeyPressed && _current->key.code == _key;
}

bool Input::IsKeyUp(const sf::Keyboard::Key& _key)
{
    const sf::Event* _current = Event::currentEvent;

    if (_current == nullptr)
        return false;

    return _current->type == sf::Event::KeyReleased && _current->key.code == _key;
}
#pragma endregion methods