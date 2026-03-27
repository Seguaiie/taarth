#pragma once
#include <SFML/Graphics.hpp>


class Game
{	
private:
	sf::RenderWindow _window;

public:
	Game();
	~Game();

	void run();
};

