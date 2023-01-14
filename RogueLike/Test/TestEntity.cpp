#include "TestEntity.h"
#include "../Time/Time.h"
#include "../Input/Input.h"

TestEntity::TestEntity()
{
	
}
TestEntity::~TestEntity(){}
void TestEntity::OnDraw()
{
	Draw(player.GetDrawable());
	Draw(monster.GetDrawable());
}
void TestEntity::OnUpdate()
{
	if (Input::IsKeyDown(sf::Keyboard::Z))
		player.SetPosition(player.Position() + sf::Vector2f(0, -10));
	if (Input::IsKeyDown(sf::Keyboard::Q))
		player.SetPosition(player.Position() + sf::Vector2f(-10, 0));
	if (Input::IsKeyDown(sf::Keyboard::S))
		player.SetPosition(player.Position() + sf::Vector2f(0, 10));
	if (Input::IsKeyDown(sf::Keyboard::D))
		player.SetPosition(player.Position() + sf::Vector2f(10, 0));

}

