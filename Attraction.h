#pragma once // Empêche les inclusions multiples du fichier

#include "Joueur.h" // Inclusion de la classe Joueur
#include "Case.h"   // Inclusion de la classe de base Case

// Déclaration de la classe Attraction, qui hérite de la classe Case
class Attraction : public Case {
private:
    short price;       // Prix d'achat de l'attraction
    Joueur* owner;     // Pointeur vers le propriétaire de l'attraction

public:
    // Constructeur : initialise le nom de l'attraction et son prix
    Attraction(const std::string& name, short price, Joueur* startOwner);

    // Accesseur : retourne le prix de l'attraction
    short getPrice();

    // Mutateur : définit le propriétaire de l'attraction
    void setOwner(Joueur& own);

    // Accesseur : retourne un pointeur vers le propriétaire de l'attraction
    Joueur* getOwner();
};
