#pragma once
#include <string>
#include "Joueur.h"

class Case
{
public:
	std::string name;

public:
	Case();
	Case(const std::string& name);
	std::string getName();

	//Attraction methodes
	virtual short getPrice();
	virtual void setOwner(Joueur& own);
	virtual Joueur* getOwner();

	//Fortune methodes
	virtual short getMoney();
	virtual void addMoney(short amount);
};

