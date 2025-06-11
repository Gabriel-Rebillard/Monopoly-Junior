#pragma once
#include <iostream>
#include <string>

#include "Joueur.h"
#include "Case.h"

// DICE FACES
#define DICE_1 "\t┌───────┐\n\t│       │\n\t│   ●   │\n\t│       │\n\t└───────┘\n"
#define DICE_2 "\t┌───────┐\n\t│ ●     │\n\t│       │\n\t│     ● │\n\t└───────┘\n"
#define DICE_3 "\t┌───────┐\n\t│ ●     │\n\t│   ●   │\n\t│     ● │\n\t└───────┘\n"
#define DICE_4 "\t┌───────┐\n\t│ ●   ● │\n\t│       │\n\t│ ●   ● │\n\t└───────┘\n"
#define DICE_5 "\t┌───────┐\n\t│ ●   ● │\n\t│   ●   │\n\t│ ●   ● │\n\t└───────┘\n"
#define DICE_6 "\t┌───────┐\n\t│ ●   ● │\n\t│ ●   ● │\n\t│ ●   ● │\n\t└───────┘\n"
#define selectDiceFace(face) face == 1 ? DICE_1 : face == 2 ? DICE_2 : face == 3 ? DICE_3 : face == 4 ? DICE_4 : face == 5 ? DICE_5 : DICE_6

class Display
{
public:
	void displayCase(Case& c);
	void displayCard(const std::string& text);

	void displayTurnBeginning(Joueur& player, Case& c);
	void displayDice(short dice1, short dice2);

	bool displayBuyChoice(Case* attraction);
	void displayNotEnoughMoney();

	void displayFreeStand(Case& attraction, bool canBePlaced, Joueur oldOwner);
	void displayFreeStand(bool canBePlaced);

	void displayCoffee(Joueur& joueur);
	void displayTrainStation(Joueur& joueur);
	void DisplayStartCase(Joueur& joueur, bool passed);
	void displayFortune(Joueur& joueur, short amount);
	void displayShowCase(Joueur& joueur);
	void displayRent(Joueur& joueur, Joueur& owner, short amount);
};
