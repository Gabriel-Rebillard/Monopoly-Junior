#include "Attraction.h"

Attraction::Attraction(const std::string& name, short price)
	: price(price), Case(name), owner(NULL)
{
}

short Attraction::getPrice()
{
	return price;
}

void Attraction::setOwner(Joueur& own)
{
	owner = own;
}

Joueur Attraction::getOwner()
{
	return owner;
}
