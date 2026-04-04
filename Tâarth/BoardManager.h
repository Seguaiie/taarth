#pragma once
#include "Deck.h"
#include "Containers.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include "card.h"

class BoardManager
{
private:
	Deck _deck;
	Containers _playerBoard[7][7];
	std::vector<card> _leftReserve;
	std::vector<card> _rightReserve;
	std::queue<card> _inGameDeck;
	card _selectedCard;
	int _x, _y;

public:

	BoardManager();
	~BoardManager();

	//getters
	card getSelectedCard() const;
	int getX() const;
	int getY() const;


	bool placeCardOnBoard(card &card, int x, int y, int player);

	std::queue<card> setupBoard();
	void draw(sf::RenderWindow& window);
	void resetBoard();

	bool checkIfCardClicked(sf::RenderWindow& window);

};



