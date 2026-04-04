#include "Game.h"

using namespace sf;
using namespace std;

Game::Game()
{
	_window.create(sf::VideoMode(1000, 1100), "taarth");
	_inGameDeck = _boardManager.setupBoard();
	setHands();
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

			gameStateHandler();
			_window.display();

			sf::sleep(sf::milliseconds(95));
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

void Game::gameStateHandler()
{

	switch (_gameState)
	{
		//affiche seulement le plateau de jeu
		case 0: 
			_boardManager.draw(_window);

			if (checkClickedCard() == true) {

				if (_curentPlayer == 1) {

					int selectedCard = _player1.getIndexSelectedCard();
					_player1.removeCardFromHand(selectedCard);
					
					if (_boardManager.placeCardOnBoard(_selected, _boardManager.getX(), _boardManager.getY(), 1) == true) {
						_curentPlayer = 2;
						_gameState = 2;
					}
					else{
						cout << "Invalid move, try again!" << endl;
					}
					
					break;
				}
				else if (_curentPlayer == 2) {

					int selectedCard = _player2.getIndexSelectedCard();
					_player2.removeCardFromHand(selectedCard);
				
					if (_boardManager.placeCardOnBoard(_selected, _boardManager.getX(), _boardManager.getY(), 2) == true) {
						
						_curentPlayer = 1;
						_gameState = 1;
					}
					else {
						cout << "Invalid move, try again!" << endl;
					}
					break;
				}
			}
			break;

			//affiche seulement les cartes en main du joueur 1
		case 1:
			cout << "Player 1's turn" << endl;

			_window.clear();
			_player1.displayHand(_window);

			if (_player1.checkHandClicked(_window) == true) {
				_gameState = 0;
				_selected = _player1.getSelectedCard();
			}
			break;

			//affiche les cartes en main du joueur 2
		case 2:
			cout << "Player 2's turn" << endl;

			_curentPlayer = 2;
			_window.clear();
			_player2.displayHand(_window);

			if (_player2.checkHandClicked(_window) == true) {
				_gameState = 0;
				_selected = _player2.getSelectedCard();
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
