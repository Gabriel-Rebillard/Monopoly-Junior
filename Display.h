#pragma once
#include <iostream>
#include <string>

#include "Joueur.h"
#include "Case.h"

// Définition des visuels ASCII pour chaque face de dé
#define DICE_1 "\t┌───────┐\n\t│       │\n\t│   ●   │\n\t│       │\n\t└───────┘\n"
#define DICE_2 "\t┌───────┐\n\t│ ●     │\n\t│       │\n\t│     ● │\n\t└───────┘\n"
#define DICE_3 "\t┌───────┐\n\t│ ●     │\n\t│   ●   │\n\t│     ● │\n\t└───────┘\n"
#define DICE_4 "\t┌───────┐\n\t│ ●   ● │\n\t│       │\n\t│ ●   ● │\n\t└───────┘\n"
#define DICE_5 "\t┌───────┐\n\t│ ●   ● │\n\t│   ●   │\n\t│ ●   ● │\n\t└───────┘\n"
#define DICE_6 "\t┌───────┐\n\t│ ●   ● │\n\t│ ●   ● │\n\t│ ●   ● │\n\t└───────┘\n"

// Sélecteur de visuel de dé en fonction de la valeur
#define selectDiceFace(face) face == 1 ? DICE_1 : face == 2 ? DICE_2 : face == 3 ? DICE_3 : face == 4 ? DICE_4 : face == 5 ? DICE_5 : DICE_6

// Classe Display : responsable de l'affichage des informations du jeu
class Display
{
public:
	// Affiche les informations d'une case du plateau
	void displayCase(Case& c);

	// Affiche une carte avec un texte (ex : carte chance)
	void displayCard(const std::string& text);

	// Affiche le début du tour d'un joueur
	void displayTurnBeginning(Joueur& player, Case& c);

	// Affiche les deux dés lancés
	void displayDice(short dice1, short dice2);

	// Demande au joueur s'il souhaite acheter une attraction
	bool displayBuyChoice(Case* attraction);

	// Affiche un message lorsque le joueur n'a pas assez d'argent pour acheter
	void displayNotEnoughMoney();

	// Affiche un message lorsque le joueur est éliminé
	void displayElimination(Joueur& player);

	// Affiche la possibilité d'installer un stand gratuit sur une attraction
	void displayFreeStand(Case& attraction, bool canBePlaced, Joueur oldOwner);

	// Surcharge : affiche seulement si un stand peut être placé
	void displayFreeStand(bool canBePlaced);

	// Affiche le passage par le café (bonus ou effet quelconque)
	void displayCoffee(Joueur& joueur);

	// Affiche le passage à la gare
	void displayTrainStation();

	// Affiche le passage ou non par la case départ
	void DisplayStartCase(Joueur& joueur, bool passed);

	// Affiche l'effet d'une carte fortune avec un montant
	void displayFortune(Joueur& joueur, short amount);

	// Affiche l'effet de la case "vitrine" ou événement spécial
	void displayShowCase(Joueur& joueur);

	// Affiche le paiement d’un loyer à un propriétaire
	void displayRent(Joueur& joueur, Joueur& owner, short amount);
};
