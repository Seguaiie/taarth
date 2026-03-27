#include "Carte.h"
using namespace std;	


Carte::Carte()
{
	_name = " ";
	_description = " ";
	_attack = 0;
}

Carte::Carte(std::string name, std::string description, int attack)
{
	_name = name;
	_description = description;
	_attack = attack;	
}
