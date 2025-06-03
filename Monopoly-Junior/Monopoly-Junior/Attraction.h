#pragma once
#include "Joueur.h"
#include "Case.h"
#include <string>

class Attraction : public Case{
private:
	short price;
	Joueur owner;

public:
	Attraction(const std::string& name, short price);
	void setOwner(Joueur& own);
	Joueur getOwner();
};
