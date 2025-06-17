#include "Fortune.h"

// Constructeur : initialise une case Fortune avec un nom, et l'argent à 0
Fortune::Fortune(const std::string& name)
	: money(0), Case(name) // Appelle le constructeur de la classe de base Case avec le nom
{
}

// Méthode pour récupérer l'argent stocké sur la case
short Fortune::getMoney()
{
	short m = money;  // On stocke la somme actuelle
	money = 0;        // On vide la case (l'argent est récupéré)
	return m;         // On retourne la somme récupérée
}

// Méthode pour ajouter de l'argent sur la case
void Fortune::addMoney(short amount)
{
	money += abs(amount);  // On ajoute la valeur absolue pour éviter les montants négatifs
}
