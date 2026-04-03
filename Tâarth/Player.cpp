#include "Player.h"

using namespace std;
using namespace sf;

Player::Player()
{
	_handIsEmpty = true;
	for (int i = 0; i < 7; i++)
	{
		_hand[i] = card();
	}
}

Player::~Player()
{
	_handIsEmpty = true;

	for (int i = 0; i < 7; i++)
	{
		_hand[i] = card();
	}
}

void Player::addCardToHand(const card& newCard)
{
	for (int i = 0; i < 7; i++)
	{
		if (_hand[i].getName() == "")
		{
			_hand[i] = newCard;
			break;
		}
	}
}



card Player::getCard(int index) const
{
	return _hand[index];
}

bool Player::isHandEmpty() const
{
	for (int i = 0; i < 7; i++)
	{
		if (_hand[i].getName() != "")
		{
			return false;
		}
	}

	return false;
}

bool Player::isCardEmpty(int index) const
{
	if (_hand[index].getName() == "")
	{
		return true;
	}

	return false;
}

int Player::countNumberOfCards() const
{
	for (int i = 0; i < 7; i++)
	{
		if (_hand[i].getName() != "")
		{
			return i + 1;
		}
	}
	return 0;
}

card Player::removeCardFromHand(int index)
{
	card oldCard = _hand[index];

	_hand[index] = card();

	return oldCard;
}



void Player::displayHand(sf::RenderWindow& window) const
{

	if (!isHandEmpty())
	{
		int index = 0;

		do {
			_hand[index].displayCard(window, 200.f + index * 100.f, 300.f);
			
			cout << "index: "  << index<< _hand[index].getName() << endl;
			index++;

		} while (isCardEmpty(index) == false);
	}
}
