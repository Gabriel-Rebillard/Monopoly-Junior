#include "Display.h"
#include "Joueur.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


void Display::write_case(Joueur& joueur, Case& case)
{
	std::cout << joueur.getName() << "Vous etes sur la case" << case.getPosition() << std::endl;
}

void Display::write_chance(Joueur& joueur)
{
	std::cout << joueur.getName() << "Vous etes sur une carte chance!!!" << std::endl;
}



void Display::write_buy(Joueur& joueur)
{
	std::cout << joueur.getName() << "Voulez vous acheter cette attraction"  << std::endl;
}

void Display::write_prison(Joueur& joueur)
{
	std::cout << joueur.getName() << "Vous etes sur la case aller en prison paie 3$ pout prendre le bus qui vous menera jusqu'a la case prison sans prendre largent de la case départ"  << std::endl;
}

void Display::write_gare(Joueur& joueur)
{
	std::cout << joueur.getName() << "Vous etes dans la gare relancé le dé"  << std::endl;
}

void Display::write_caseDepart(Joueur& joueur)
{
	std::cout << joueur.getName() << "Vous etes sur la case départ recevez 2$" << std::endl;
}

void Display::write_fortune(Joueur& joueur)
{
	std::cout << joueur.getName() << "Vous etes sur la case fortune prenez tout l'argent bien jouer" << std::endl;
}

void Display::write_newtour(Joueur& joueur)
{
	std::cout << joueur.getName() << "Vous avez fait un nouveau tour du plateau recevez 2$" << std::endl;
}

void Display::write_taxe(Joueur& joueur)
{
	std::cout << joueur.getName() << "vous etes sur une case de spectacle payer 2$" << std::endl;
}
