#include "Case.h"

// Constructeur par défaut de la classe Case
Case::Case()
{
}

// Constructeur avec paramètre : initialise le nom de la case
Case::Case(const std::string& name)
    : name(name) // Utilise une liste d'initialisation pour définir le nom
{}

// Accesseur : retourne le nom de la case
std::string Case::getName()
{
    return name;
}

// Méthode virtuelle par défaut : retourne 0 pour le prix
// Doit être redéfinie dans les classes dérivées comme Attraction
short Case::getPrice()
{
    return 0;
}

// Méthode virtuelle vide : destinée à être redéfinie dans les classes filles
// Ici, elle ne fait rien
void Case::setOwner(Joueur& own)
{
}

// Méthode virtuelle : retourne un pointeur nul par défaut
// À redéfinir dans une classe qui gère un propriétaire
Joueur* Case::getOwner()
{
    return nullptr;
}

// Méthode virtuelle : retourne 0 par défaut pour l'argent sur la case
// Utile dans des classes comme une banque ou une case spéciale
short Case::getMoney()
{
    return 0;
}

// Méthode virtuelle vide : censée ajouter de l'argent à la case
// Redéfinition attendue dans les sous-classes
void Case::addMoney(short amount)
{
}
