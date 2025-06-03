#include "Display.h"
#include "Joueur.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


void Display::write_case()
{
	std::cout << getName() << "Vous etes sur la case" << getPosition() << std::endl;
}

void Display::write_chance()
{
	std::cout << getName() << "Vous etes sur une carte chance!!!" <<  << std::endl;
}


void Display::write_intro()
{
	std::cout << "Bienvenue dans Monopoly junior" << std::endl;
}

void Display::write_buy()
{
	std::cout << getName() << "Voulez vous acheter cette attraction"  << std::endl;
}

void Display::write_prison()
{
	std::cout << getName() << "Vous etes sur la case aller en prison paie 3$ pout prendre le bus qui vous menera jusqu'a la case prison sans prendre largent de la case départ"  << std::endl;
}

void Display::write_gare()
{
	std::cout << getName() << "Vous etes dans la gare relancé le dé"  << std::endl;
}

void Display::write_caseDepart()
{
	std::cout << getName() << "Vous etes sur la case départ recevez 2$" << std::endl;
}

void Display::write_fortune()
{
	std::cout << getName() << "Vous etes sur la case fortune prenez tout l'argent bien jouer" << std::endl;
}

void Display::write_newtour()
{
	std::cout << getName() << "Vous avez fait un nouveau tour du plateau recevez 2$" << std::endl;
}

void Display::write_taxe()
{
	std::cout << getName() << "vous etes sur une case de spectacle payer 2$" << std::endl;
}
