#include "Monster.h"

Monster::Monster(class Window* _owner, const sf::Vector2f& _position, const std::string& _name)
    : Entity(_owner, "../Assets/Monster/ghost.png", _position, _name) {}

void Monster::OnUpdate()
{
}
