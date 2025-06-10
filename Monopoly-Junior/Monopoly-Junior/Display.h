#pragma once
#include <iostream>
#include <string>

#include "Joueur.h"
#include "Case.h"

class Display
{
public:
	void displayCase(Case& c);
	void displayCard(const std::string& text);
	bool displayBuyChoice();
	void displayCoffee(Joueur& joueur);
	void displayTrainStation(Joueur& joueur);
	void DisplayStartCase(Joueur& joueur, bool passed);
	void displayFortune(Joueur& joueur, short amount);
	void displayShowCase(Joueur& joueur);
	void displayRent(Joueur& joueur, Joueur& owner, short amount);
};
