#include "PlayerHand.h"

PlayerHand::PlayerHand()
{
}

PlayerHand::~PlayerHand()
{
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
