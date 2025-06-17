#pragma once
#include <string>

// Classe représentant un joueur dans le jeu
class Joueur
{
private:
	std::string name;    // Nom du joueur
	short money;         // Montant d'argent que possède le joueur
	short position;      // Position actuelle du joueur sur le plateau (0 à 31)

public:
	// Constructeur : initialise le joueur avec un nom, 31 pièces, position à 0
	Joueur(const std::string& playerName);

	// Retourne le nom du joueur
	std::string getName();

	// Retourne la position actuelle sur le plateau
	short getPosition();

	// Retourne l'argent actuel du joueur
	short getMoney();

	// Modifie l'argent du joueur (ajoute ou retire un montant)
	void modifyMoney(short montant);

	// Modifie la position du joueur (avec retour à 0 après 31 via modulo)
	void setPosition(short pos);

	// Simule un lancer de dé (entre 1 et 6)
	short rollDice();
};
