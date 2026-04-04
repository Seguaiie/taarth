#pragma once
#include <SFML/Graphics.hpp>
#include "card.h"


class Containers
{
private:
	int _playerPacedCard = 0;

	bool _empty = true;
	bool _reserved = false;
	bool _clicked = false;
	bool _wasPressed = false;

	card _card;

	sf::RectangleShape _shape;
	sf::Texture	_texture;


public:
	Containers();
	~Containers();

	//Setters
	void setPosition(float x, float y);
	void setReserved(bool reserved);
	void setEmpty(bool empty);
	void resetClicked();

	//getters
	bool isEmpty() const;
	bool isReserved() const;
	bool checkIfClicked(sf::RenderWindow& window);
	card getCard() const;
	int getPlayerPacedCard() const;
	

	void addCard(const card& newCard, int player);
	void draw(sf::RenderWindow& window);
};

