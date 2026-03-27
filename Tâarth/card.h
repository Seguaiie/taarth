#pragma once
#include <string>

class card
{
private:
	std::string _name;
	std::string _description;
	int _health;
	int _attack;	
public:
	card();
	card(std::string name, std::string description, int health, int attack);
	~card();

	// Getters
	std::string getName() const;
	std::string getDescription() const;
	int getHealth() const;
	int getAttack() const;

	//Setters
	void setName(const std::string& name);
	void setDescription(const std::string& description);
	void setHealth(int health);
	void setAttack(int attack);


};

