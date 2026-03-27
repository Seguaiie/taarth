#include "Deck.h"

Deck::Deck()
{

	for (int i = 0; i < _size; i++)
	{
		//setup mosketman 
		if (i < 21) {

			_cards[i] = card("Mousquetaire", "Plus que l'on est mieux c'est.", 6, 1);
		}
		//setup CAVALIER
		else if(i > 21 && i < 31)  {
				
			_cards[i] = card("Cavalier", "Unite mobile.", 8, 5);
		}
		//setup éclaireur
		else if (i > 31 && i < 36) {
			_cards[i] = card("Eclaireur", "Unite de reconnaissance.", 0, 0);
		}
		//setup canon
		else if (i > 36 && i < 43) {
			_cards[i] = card("Canon", "Unite de siege.", 6, 3);
		}


	}

}

Deck::~Deck()
{

}
