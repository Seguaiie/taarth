#pragma once
#include "Deck.h"
#include "Containers.h"
#include <SFML/Graphics.hpp>
#include <vector>

class BoardManager
{
private:
	Deck _deck;
	Containers _playerBoard[7][7];
	std::vector<Containers> _leftReserve;
	std::vector<Containers> _rightReserve;

public:

	BoardManager();
	~BoardManager();


	void setupBoard(sf::RenderWindow& window);
	void resetBoard();
};


