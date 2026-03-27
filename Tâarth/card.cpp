#include "card.h"

card::card()
{
	_name = "";
	_description = "";
	_health = 0;
	_attack = 0;
}

card::card(std::string name, std::string description, int health, int attack)
{
	_name = name;
	_description = description;
	_health = health;
	_attack = attack;	
}

card::~card()
{
}



std::string card::getName() const
{
	return _name;
}

std::string card::getDescription() const
{
	return _description;
}

int card::getHealth() const
{
	return _health;
}

int card::getAttack() const
{
	return _attack;
}

void card::setName(const std::string& name)
{
	_name = name;
}

void card::setDescription(const std::string& description)
{
	_description = description;
}

void card::setHealth(int health)
{
	_health = health;
}

void card::setAttack(int attack)
{
	_attack = attack;
}
