#include "Joueur.h"

Joueur::Joueur(const std::string& playerName) : name(playerName), money(31), position(0)
{
}

std::string Joueur::getName()
{
	return name;
}

void Joueur::modifyMoney(short montant)
{
	money += montant;
}

void Joueur::setPosition(short pos)
{
	position = pos % 32;
}

short Joueur::getPosition()
{
	return position;
}

short Joueur::rollDice()
{
	return (std::rand() %6) +1;
}

short Joueur::getMoney()
{
	return money;
}
