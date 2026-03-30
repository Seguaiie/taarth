#pragma once
#include "card.h"
#include <vector>


class Deck
{
private:
	int _size = 63;
	std::vector<card> _cards;


public:
	Deck();
	~Deck();

	void shuffle();
	void print();
	
	//getteur
	int size();
	card getCard(int index);

};

