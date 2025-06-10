#include "Display.h"

void Display::displayCase(Case& c)
{
	std::cout << "\t -> Vous etes sur la case " << c.getName() << std::endl;

	short length = c.getName().length() + 2 - (c.getName().find('é') < 100 ? 1 : 0) - (c.getName().find('â') < 100 ? 1 : 0);
	
	std::cout << "\t╔";
	for (short i = 0; i < length; i++)
		std::cout << "═";
	std::cout << "╗\n\t║ " << c.getName() << " ║\n\t╚";
	for (short i = 0; i < length; i++)
		std::cout << "═";
	std::cout << "╝\n\n";
}

void Display::displayCard(const std::string& text)
{
	std::cout << "\t ==> Vous etes sur une carte chance !!!\n\t\tCarte :\n" ;

	short length = text.length() + 2 - (text.find('é') < 100 ? 1 : 0) - (text.find('ç') < 100 ? 1 : 0);
	std::cout << "\t┌";
	for (short i = 0; i < length; i++)
		std::cout << "─";
	std::cout << "┐\n\t│ " << text << " │\n\t└";
	for (short i = 0; i < length; i++)
		std::cout << "─";
	std::cout << "┘\n\n";

}

bool Display::displayBuyChoice()
{
	char choice;

	do {
		std::cout << "\tVoulez vous acheter cette attraction ? (0 : non / 1 : oui) : " << std::endl;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (choice != '0' && choice != '1');

	return choice - '0';
}

void Display::displayCoffee(Joueur& joueur)
{
	std::cout << joueur.getName() << " : Vous êtes sur la case aller au café :  payez 3$ pout prendre le bus qui vous menera jusqu'a la case café sans prendre l'argent de la case départ."  << std::endl;
}

void Display::displayTrainStation(Joueur& joueur)
{
	std::cout << joueur.getName() << " : Vous êtes dans une gare, relancez le dé !"  << std::endl;
}

void Display::DisplayStartCase(Joueur& joueur, bool passed)
{
	if (passed)
		std::cout << joueur.getName() << " : Vous avez passé la case départ et reçu 2$." << std::endl;
	else
		std::cout << joueur.getName() << " : Vous êtes sur la case départ, recevez 4$ !" << std::endl;
}

void Display::displayFortune(Joueur& joueur, short amount)
{
	std::cout << joueur.getName() << " : Vous êtes sur la case fortune, récupérez les " << amount << "$ qui s'y trouvent !" << std::endl;
}

void Display::displayShowCase(Joueur& joueur)
{
	std::cout << joueur.getName() << " : Vous êtes sur une case de spectacle, payez 2$." << std::endl;
}

void Display::displayRent(Joueur& joueur, Joueur& owner, short amount)
{
	std::cout << joueur.getName() << " : Payez un loyer de " << amount << "$ à " << owner.getName() << std::endl;
}
