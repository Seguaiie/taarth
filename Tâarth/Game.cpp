#include "Game.h"

using namespace sf;
using namespace std;

Game::Game()
{
	_window.create(sf::VideoMode(1000, 1100), "taarth");
}

Game::~Game()
{
}

void Game::run()
{
	_inGameDeck = _boardManager.setupBoard();
	
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
		}
		_window.clear();

	
		//plateau de jeu avec la réseve initialisé
		_boardManager.draw(_window);

		_window.display();
	}
}

void Game::setHands()
{
	for (int i = 0; i < 7; i++) {

		card c = _inGameDeck.front();
		_player1.addCardToHand(c);
		_inGameDeck.pop();
	}

	for (int i = 0; i < 7; i++) {

		card c = _inGameDeck.front();
		_player2.addCardToHand(c);
		_inGameDeck.pop();
	}
}
