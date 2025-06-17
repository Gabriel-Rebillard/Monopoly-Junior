#pragma once // Évite les inclusions multiples du fichier

#include <string> // Nécessaire pour utiliser std::string

// Déclaration de la classe Card (Carte)
class Card
{
private:
    std::string text;     // Texte de la carte (description ou instruction)
    short destination;    // Destination associée à la carte (peut représenter une case du plateau, par exemple)

public:
    // Constructeur : initialise le texte et la destination de la carte
    Card(const std::string& text, short destination);

    // Accesseur : retourne le texte de la carte
    std::string getText();

    // Accesseur : retourne la destination de la carte
    short getDestination();
};
