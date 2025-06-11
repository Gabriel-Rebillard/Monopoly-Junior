#pragma once
#include "Joueur.h"
#include "Case.h"

class Attraction : public Case{
private:
	short price;
	Joueur* owner;

public:
	Attraction(const std::string& name, short price);

	short getPrice();

	void setOwner(Joueur& own);
	Joueur* getOwner();
};
