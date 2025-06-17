#pragma once // Empêche les inclusions multiples du fichier

#include <string>   // Pour utiliser std::string
#include "Joueur.h" // Pour utiliser la classe Joueur dans les méthodes virtuelles

// Classe de base représentant une case du plateau de jeu
class Case
{
public:
    std::string name; // Nom de la case (peut être affiché sur le plateau ou dans l'interface)

public:
    // Constructeur par défaut
    Case();

    // Constructeur avec nom de la case
    Case(const std::string& name);

    // Accesseur : retourne le nom de la case
    std::string getName();

    // Méthodes virtuelles pour les types de case "Attraction"
    
    // Retourne le prix de la case (0 par défaut)
    virtual short getPrice();

    // Définit le propriétaire de la case (ne fait rien par défaut)
    virtual void setOwner(Joueur& own);

    // Retourne le propriétaire de la case (nullptr par défaut)
    virtual Joueur* getOwner();

    // Méthodes virtuelles pour les types de case "Fortune" (ou autres cases spéciales)

    // Retourne l'argent placé sur la case (0 par défaut)
    virtual short getMoney();

    // Ajoute de l'argent à la case (implémentation vide par défaut)
    virtual void addMoney(short amount);
};
