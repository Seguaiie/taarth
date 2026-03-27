#pragma once
#include "card.h"
#include "Containers.h"

class PlayerHand
{
private:
	int _size = 7;
	Containers _hand[7];

public:
	PlayerHand();
	~PlayerHand();

	//guetters
	card getCard(int index);


	//setters
	void setCard(const card& newCard, int index);


	void distributeCard(const card& newCard);
};

