#include "PlayerHand.h"

PlayerHand::PlayerHand()
{
}

PlayerHand::~PlayerHand()
{
}

card PlayerHand::getCard(int index)
{
	return _hand[index].getCard();
}

void PlayerHand::distributeCard(const card& newCard)
{
	for (int i = 0; i < _size; i++)
	{
		if (_hand[i].isEmpty())
		{
			_hand[i].addCard(newCard);
			break;
		}
	}
}

void PlayerHand::setCard(const card& newCard, int index)
{
	if (_hand[index].isEmpty()) {
		_hand[index].addCard(newCard);
	}
}
