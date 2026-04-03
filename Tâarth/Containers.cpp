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

bool Containers::checkIfClicked(sf::RenderWindow& window)
{

	sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePos = window.mapPixelToCoords(mousePixelPos);

	if (_shape.getGlobalBounds().contains(mousePos))
	{
		// La souris est sur le container
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_clicked = true;
			return true;
		}
	}
}

void Containers::draw(sf::RenderWindow& window)
{
	if (_clicked == true)
	{
		_shape.setFillColor(sf::Color::Yellow);
	}
	else if (_empty == true)
	{
		_shape.setFillColor(sf::Color::Green);
	}
	else
	{
		_shape.setFillColor(sf::Color::Red);
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
