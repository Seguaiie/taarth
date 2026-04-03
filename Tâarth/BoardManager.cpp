#include "BoardManager.h"

using namespace std;
using namespace sf;


BoardManager::BoardManager()
{
}

BoardManager::~BoardManager()
{
}

std::queue<card> BoardManager::setupBoard()
{
	_deck.shuffle();

	for (int i = 0; i < _deck.size(); i++) {
		_inGameDeck.push(_deck.getCard(i));
	}
	
	//initialisation des reserve 
	for (int i= 0; i < 10; i++) {

		card c = _inGameDeck.front();
		_inGameDeck.pop();

		if (i < 5) {
			_leftReserve.push_back(c);
		}
		else {
			_rightReserve.push_back(c);
		}

		
	}

	//initialise la réservee et place les cartes de la réserve sur le jeu 
	for (int i = 0; i < 7; i++)
	{

		for (int j = 0; j < 7; j++)
		{
			_playerBoard[i][j].setPosition(100.f + j * 125.f, 850.f - i * 125.f);

			if (i >= 1 && i <= 5 && j == 0) {

				_playerBoard[i][j].setReserved(true);
				_playerBoard[i][j].addCard(_leftReserve[i - 1]);
			}
			else if (i >= 1 && i <= 5 && j == 6) {

				_playerBoard[i][j].setReserved(true);
				_playerBoard[i][j].addCard(_rightReserve[i - 1]);

			}

			
		}
	}

	return _inGameDeck;
	
}

void BoardManager::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			_playerBoard[i][j].draw(window);
		}
	}
}

void BoardManager::resetBoard()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++){

			_playerBoard[i][j].setReserved(false);
			
			_playerBoard[i][j].setEmpty(true);
		}
	}

}

bool BoardManager::checkIfCardClicked(sf::RenderWindow& window)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (_playerBoard[i][j].checkIfClicked(window) == true)
			{
				return true;
			}
		}
	}
	return false;
}
