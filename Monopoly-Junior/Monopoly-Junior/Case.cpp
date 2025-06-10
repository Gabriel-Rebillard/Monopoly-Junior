#include "Case.h"

Case::Case()
{
}

Case::Case(const std::string& name)
	: name(name)
{}

std::string Case::getName()
{
	return name;
}

short Case::getPrice()
{
	return 0;
}

void Case::setOwner(Joueur& own)
{
}

Joueur* Case::getOwner()
{
	return nullptr;
}

short Case::getMoney()
{
	return 0;
}

void Case::addMoney(short amount)
{
}
