#include "TestEntity.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "../Entity/Player/Player.h"
#include "../Entity/Monster/Monster.h"

void TestEntity::Play()
{
	Player _player;
	Monster _monster;
	
	sf::RenderWindow _window(sf::VideoMode(900, 900), "BIRD!");

	sf::Texture _texture;
	if (!_texture.loadFromFile("assets/Sprites/Heros/mage.png"))
	{
		std::cout << "Impossible to load!" << std::endl;
		return;
	}



	sf::Sprite _heros;
	_heros.setTexture(_texture);
	_heros.setPosition(sf::Vector2f(100, 100));

	while (_window.isOpen())
	{
		sf::Event _event;
		while (_window.pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
				_window.close();
		}
		_window.clear();
		_window.draw(_heros);
		_window.display();

	}
}
