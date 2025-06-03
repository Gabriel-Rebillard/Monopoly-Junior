#pragma once
#include "Joueur.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Game"

class Display
{
public:
	void write_case();
	void write_chance();
	void write_intro();
	void write_buy();
	void write_prison();
	void write_gare();
	void write_caseDepart();
	void write_fortune();
	void write_newtour();
	void write_taxe();

};
