#pragma once
#include "Deck.h"
#include "Containers.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>


class BoardManager
{
private:
	Deck _deck;
	Containers _playerBoard[7][7];
	std::vector<card> _leftReserve;
	std::vector<card> _rightReserve;
	std::queue<card> _inGameDeck;

public:

	BoardManager();
	~BoardManager();


	//getteurs


	std::queue<card> setupBoard();
	void draw(sf::RenderWindow& window);
	void resetBoard();

	bool checkIfCardClicked(sf::RenderWindow& window);

};



