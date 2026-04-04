#include "Containers.h"
using namespace sf;
using namespace std;

Containers::Containers()
{
	_shape.setSize(sf::Vector2f(50.f, 75.f));
	_empty = true;
}

Containers::~Containers()
{
}

void Containers::addCard(const card& newCard, int player)
{
	_card = newCard;
	_empty = false;
	_playerPacedCard = player;
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

int Containers::getPlayerPacedCard() const
{
	return _playerPacedCard;
}

bool Containers::checkIfClicked(sf::RenderWindow& window)
{

	sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePos = window.mapPixelToCoords(mousePixelPos);

	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	if (_shape.getGlobalBounds().contains(mousePos))
	{
		// Détecte seulement le moment où le bouton vient d'être pressé
		if (isPressed == true )
		{
			_wasPressed = true;
			_clicked = true;
			return true;
		}
	}

	// Reset quand le bouton est relâché
	if (!isPressed)
		_wasPressed = false;

	return false;
}

void Containers::draw(sf::RenderWindow& window)
{

	if( _reserved == true)
	{
		_texture.loadFromFile("ressources/art/backCover.png");

		_shape.setTexture(&_texture);
		window.draw(_shape);
	}
	else if (_empty == true)
	{
		_texture.loadFromFile("ressources/art/empty.png");

		_shape.setTexture(&_texture);
		window.draw(_shape);
	}
	else if (_empty == false)
	{
		string cardName = _card.getName();

		if (cardName == "Mousquetaire")
		{
			_texture.loadFromFile("ressources/art/mousquetaire.png");
		}
		else if (cardName == "Cavalier")
		{
			_texture.loadFromFile("ressources/art/cavalier.png");
		}
		else if (cardName == "Eclaireur")
		{
			_texture.loadFromFile("ressources/art/eclaireur.png");
		}
		else if (cardName == "Canon")
		{
			_texture.loadFromFile("ressources/art/canon.png");
		}
		else if (cardName == "Prophète")
		{
			_texture.loadFromFile("ressources/art/prohete.png");
		}

		_shape.setTexture(&_texture);
		window.draw(_shape);
	}
	else
	{
		_shape.setFillColor(Color::Red);
		window.draw(_shape);
	}
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

void Containers::resetClicked()
{
	_clicked = false;
}
