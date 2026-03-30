#pragma once
#include <SFML/Graphics.hpp>
#include "BoardManager.h"
#include "Player.h"
#include "Deck.h"


class Game
{	
private:
	sf::RenderWindow _window;
	BoardManager _boardManager;
	Player _player1;
	Player _player2;


public:
	Game();
	~Game();

	void run();
};

