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
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
		}
		_window.clear();

		_inGameDeck = _boardManager.setupBoard();
		setHands();

		gameStateHandler(1);
		
		checkClickedCard();
		

		_window.display();
	}
}

void Game::setHands()
{
	// Distribuer les cartes aux joueurs
	for (int i = 0; i < 7; i++) {		

		// Distribuer une carte au joueur 1
		card c = _inGameDeck.front();
		_player1.addCardToHand(c);
		_inGameDeck.pop();
		
		// Distribuer une carte au joueur 2
		card c2 = _inGameDeck.front();
		_player2.addCardToHand(c2);
		_inGameDeck.pop();
	}
}

void Game::gameStateHandler(int gameState)
{
	_window.clear();
	_gameState = gameState;

	switch (_gameState)
	{
		//affiche seulement le plateau de jeu
		case 0: 
			_boardManager.draw(_window);
			break;

			//affiche seulement les cartes en main du joueur 1
		case 1:
			_window.clear();
			_player1.displayHand(_window);

			if (_player1.checkHandClicked(_window) == true) {
				_gameState = 0;
			}
			break;

			//affiche les cartes en main du joueur 2
		case 2:
			_window.clear();
			_player2.displayHand(_window);

			if (_player2.checkHandClicked(_window)) {
				_gameState = 0;
			}

			break;

		default:
			break;
	}
}

bool Game::checkClickedCard()
{
	// Vérifier si une carte a été cliquée sur le plateau de jeu
	if (_gameState == 0) {

		if (_boardManager.checkIfCardClicked(_window) == true) {

			return true;
		}
	}
	return false;
}
