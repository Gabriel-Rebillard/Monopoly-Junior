#include "Joueur.h"

// Constructeur : initialise un joueur avec un nom, 31 pièces et une position de départ à 0
Joueur::Joueur(const std::string& playerName) : name(playerName), money(31), position(0)
{
}

// Retourne le nom du joueur
std::string Joueur::getName()
{
	return name;
}

// Modifie l'argent du joueur en ajoutant (ou retirant si négatif) un montant
void Joueur::modifyMoney(short montant)
{
	money += montant;
}

// Définit la position du joueur sur le plateau (modulo 32 pour rester dans les limites)
void Joueur::setPosition(short pos)
{
	position = pos % 32;
}

// Retourne la position actuelle du joueur sur le plateau
short Joueur::getPosition()
{
	return position;
}

// Simule le lancer d’un dé (valeur entre 1 et 6)
short Joueur::rollDice()
{
	return (std::rand() % 6) + 1;
}

// Retourne l'argent actuel du joueur
short Joueur::getMoney()
{
	return money;
}
