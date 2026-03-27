#pragma once
#include <string>

class Carte
{
	private:
		std::string _name;
		std::string _description;	
		int _attack;
	public:

	Carte();
	Carte(std::string name, std::string description, int attack);
	~Carte();
};

