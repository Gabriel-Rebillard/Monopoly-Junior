#pragma once
#include "Joueur.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Game.h"
class Display
{
public:
	void write_case(Joueur& joueur, Case& case);
	void write_chance(Joueur& joueur);
	void write_buy(Joueur& joueur);
	void write_prison(Joueur& joueur);
	void write_gare(Joueur& joueur);
	void write_caseDepart(Joueur& joueur);
	void write_fortune(Joueur& joueur);
	void write_newtour(Joueur& joueur);
	void write_taxe(Joueur& joueur);


};
