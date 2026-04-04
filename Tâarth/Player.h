#pragma once
#include "card.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Containers.h"

class Player
{
	private:
		Containers _hand[7];
		bool _handIsEmpty;
		card _selectedCard;
		int _indexSelectedCard;

		

	public:

		Player();
		~Player();
		
		//setteur
		void addCardToHand(const card& newCard);

		//getteur
		card getCard(int index) const;
		card getSelectedCard() const;
		bool isHandEmpty() const;
		int getIndexSelectedCard() const;


		int countNumberOfCards() const;
		card removeCardFromHand(int index);

		void displayHand(sf::RenderWindow& window);
		bool checkHandClicked(sf::RenderWindow& window);


};

