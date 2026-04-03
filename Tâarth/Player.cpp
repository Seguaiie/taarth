#include "Player.h"

using namespace std;
using namespace sf;

Player::Player()
{
}

Player::~Player()
{
	
}

void Player::addCardToHand(const card& newCard)
{
	for (int i = 0; i < 7; i++)
	{
		if (_hand[i].isEmpty() == true)
		{
			_hand[i].addCard(newCard);
			break;
		}
	}
}

card Player::getCard(int index) const
{
	return _hand[index].getCard();
}

bool Player::isHandEmpty() const
{
	for (int i = 0; i < 7; i++)
	{
		if (_hand[i].isEmpty() == false)
		{
			return false;
		}
	}

	return true;
}

int Player::countNumberOfCards() const
{
	for (int i = 0; i < 7; i++)
	{
		if (_hand[i].isEmpty() == false)
		{
			return i + 1;
		}
	}
	return 0;
}

card Player::removeCardFromHand(int index)
{
	card oldCard = _hand[index].getCard();

	_hand[index].setEmpty(true);

	return oldCard;
}

void Player::displayHand(sf::RenderWindow& window) 
{

	if (isHandEmpty() == false)
	{	
		for (int i = 0; i < 7; i++) {
			_hand[i].setPosition(100.f + i * 125.f, 500.f);
			_hand[i].draw(window);

		}
	}
	else {
		cout << "Hand is empty" << endl;
	}
}

bool Player::checkHandClicked(sf::RenderWindow& window)
{
	for (int i = 0; i < 7; i++)
	{
		if (_hand[i].checkIfClicked(window) == true)
		{
			return true;
		}
	}
}
