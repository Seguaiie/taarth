#pragma once
#include <SFML/Graphics.hpp>
#include "card.h"


class Containers
{
private:
	bool _empty = true;
	card _card;
	sf::RectangleShape _shape;
	bool _reserved = false;


public:
	Containers();
	~Containers();



	void addCard(const card& newCard);

	

	void draw(sf::RenderWindow& window);

	//Setters
	void setPosition(float x, float y);
	void setReserved(bool reserved);
	void setEmpty(bool empty);

	//getters
	bool isEmpty() const;
	bool isReserved() const;
	card getCard() const;

};

