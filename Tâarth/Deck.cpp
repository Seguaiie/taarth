#include "Deck.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;
Deck::Deck()
{

	for (int i = 0; i < _size; i++)
	{
		//setup mosketman 
		if (i < 21) {

			_cards.push_back(card("Mousquetaire", "Plus que l'on est mieux c'est.", 6, 1));
		}
		//setup CAVALIER
		else if(i > 21 && i < 31)  {
				
			_cards.push_back(card("Cavalier", "Unite mobile.", 8, 5)) ;
		}
		//setup éclaireur
		else if (i > 31 && i < 36) {
			_cards.push_back(card("Eclaireur", "Unite de reconnaissance.", 0, 0));
		}
		//setup canon
		else if (i > 36 && i < 43) {
			_cards.push_back(card("Canon", "Unite de siege.", 6, 3));
		}
		else if (i == 44) {
			_cards.push_back(card("Prophète", "", 0, 0));
		}
		else if (i > 44 && i < 63) {
			_cards.push_back(card("Dummy", "", 6, 3));
		}


	}

}

Deck::~Deck()
{

}

void Deck::shuffle()
{
	std::mt19937 rng(std::random_device{}());
	std::shuffle(_cards.begin(), _cards.end(), rng);
}

void Deck::print()
{
	for (int i = 0; i < _cards.size(); i++) {

		cout << _cards[i].getName() << endl;
	}
}

int Deck::size()
{
	return _cards.size();
}

card Deck::getCard(int index)
{
	return _cards[index];
}
