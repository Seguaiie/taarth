#pragma once
#include <SFML/Graphics.hpp>
#include "BoardManager.h"

class Game
{	
private:
	sf::RenderWindow _window;

public:
	Game();
	~Game();

	void run();
};

