#pragma once
#include <string>

class Joueur
{
private:
	std::string name;
	short money;
	short position;

public:
	Joueur(const std::string& playerName);

	std::string getName();
	short getPosition();
	short getMoney();

	void modifyMoney(short montant);
	void setPosition(short pos);
	
	short rollDice();
};
