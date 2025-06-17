#include "Attraction.h"

// Constructeur de la classe Attraction
// Initialise l'attraction avec un nom, un prix et un propriétaire par défaut ("None")
Attraction::Attraction(const std::string& name, short price)
    : price(price), Case(name), owner(new Joueur("None")) // Initialisation des membres
{
}

// Retourne le prix de l'attraction
short Attraction::getPrice()
{
    return price;
}

// Définit le propriétaire de l'attraction
void Attraction::setOwner(Joueur& own)
{
    owner = &own; // On pointe vers le joueur passé en paramètre
}

// Retourne un pointeur vers le propriétaire de l'attraction
Joueur* Attraction::getOwner()
{
    return owner;
}
