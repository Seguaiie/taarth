#include "Game.h"

Game::Game()
{
	_window.create(sf::VideoMode(1000, 800), "taarth");
}

Game::~Game()
{
}


void Game::run()
{
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
		}
		_window.clear();
		_window.display();
	}
}
