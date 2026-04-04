#pragma once
#include <SFML/Graphics.hpp>
#include "BoardManager.h"
#include "Player.h"
#include "Deck.h"
#include "queue"
#include "card.h"


class Game
{	
private:
	sf::RenderWindow _window;

	BoardManager _boardManager;
	
	Player _player1;
	Player _player2;

	std::queue<card> _inGameDeck;

	int _gameState = 1; 
	int _curentPlayer = 1;

	bool _gameOver = false;

	card _selected;
public:
	Game();
	~Game();


	void run();
	void setHands();
	void gameStateHandler();
	bool checkClickedCard();
};

