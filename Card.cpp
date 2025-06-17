#include "Card.h"

// Constructeur de la classe Card
// Initialise la carte avec un texte descriptif et une destination
Card::Card(const std::string& text, short destination)
    : text(text), destination(destination) // Initialisation des attributs via une liste d'initialisation
{
}

// Accesseur : retourne le texte de la carte
std::string Card::getText()
{
    return text;
}

// Accesseur : retourne la destination associée à la carte
short Card::getDestination()
{
    return destination;
}
