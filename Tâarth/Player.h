#pragma once
#include "card.h"

class Player
{
	private:
		card _hand[7];
		bool _handIsEmpty;

	public:

		Player();
		~Player();
		
		//setteur
		void addCardToHand(const card& newCard);

		//getteur
		card getCard(int index) const;
		bool isHandEmpty() const;
		bool isCardEmpty(int index) const;


		int countNumberOfCards() const;
		card removeCardFromHand(int index);


};

