#pragma once
#include "Case.h"

// Classe Fortune : représente une case spéciale où de l'argent peut s'accumuler
class Fortune : public Case
{
private:
	short money;  // Montant d'argent stocké sur la case

public:
	// Constructeur : initialise le nom de la case et l'argent à zéro
	Fortune(const std::string& name);

	// Récupère l'argent disponible sur la case et le remet à zéro
	short getMoney();

	// Ajoute un montant d'argent à la case (toujours en valeur positive)
	void addMoney(short amount);
};
