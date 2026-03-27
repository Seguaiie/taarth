#include "Containers.h"

Containers::Containers()
{
	_shape.setSize(sf::Vector2f(50.f, 75.f));
}

Containers::~Containers()
{
}

void Containers::addCard(const card& newCard)
{
	_card = newCard;
	_empty = false;
}

bool Containers::isEmpty() const
{
	return _empty;
}

bool Containers::isReserved() const
{
	return _reserved;
}

card Containers::getCard() const
{
	return _card;
}

void Containers::draw(sf::RenderWindow& window)
{
	
	if (_empty == true)
	{
		_shape.setFillColor(sf::Color::Green);
	}
	else
	{
		_shape.setFillColor(sf::Color::Red);
	}

	if (_reserved == true)
	{
		_shape.setFillColor(sf::Color::Blue);
	}

	window.draw(_shape);
}

void Containers::setPosition(float x, float y)
{
	_shape.setPosition(x, y);
}

void Containers::setReserved(bool reserved)
{
	_reserved = reserved;
}

void Containers::setEmpty(bool empty)
{
	_empty = empty;
}
