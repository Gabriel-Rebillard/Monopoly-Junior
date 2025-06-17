#include "Display.h"

void Display::displayCase(Case& c)
{
	std::cout << "\n\t -> Vous êtes sur la case " << c.getName() << std::endl;

	// Longueur du texte de la case (le 'é' / 'â' / 'è' prennent deux octets au lieu d'un)
	short length = c.getName().length() + 2 - (c.getName().find('é') < 100 ? 1 : 0) - (c.getName().find('â') < 100 ? 1 : 0) - (c.getName().find('è') < 100 ? 1 : 0);

	// Afficher un cadre autour du texte
	std::cout << "\t\t╔";						// Angle supérieur gauche

	// Ligne du haut
	for (short i = 0; i < length; i++)
		std::cout << "═";
	
	std::cout << "╗\n\t\t║ " << c.getName() << " ║\n\t\t╚";		// Angle supérieur droit, coté gauche, texte, coté droit, angle inférieur gauche

	// Ligne du bas
	for (short i = 0; i < length; i++)
		std::cout << "═";
	
	std::cout << "╝\n\n";						// Angle inférieur droit
}

void Display::displayCard(const std::string& text)
{
	std::cout << "\n\t ==> Vous êtes sur une case chance !!!\n\t\tCarte :\n" ;

	// Longueur du texte de la carte (le 'é' / 'ç' prennent deux octets au lieu d'un)
	short length = text.length() + 2 - (text.find('é') < 100 ? 1 : 0) - (text.find('ç') < 100 ? 1 : 0);

	// Afficher un cadre autour du texte
	std::cout << "\t\t┌";					// Angle supérieur gauche

	// Ligne du haut
	for (short i = 0; i < length; i++)
		std::cout << "─";
	
	std::cout << "┐\n\t\t│ " << text << " │\n\t\t└";	// Angle supérieur droit, coté gauche, texte, coté droit, angle inférieur gauche

	// Ligne du bas
	for (short i = 0; i < length; i++)
		std::cout << "─";
	
	std::cout << "┘\n\n";					// Angle inférieur droit

}

void Display::displayTurnBeginning(Joueur& player, Case& c)
{
	std::cout << "\n\n\nAu tour de " << player.getName() << " de jouer.\n\t  --> Vous avez " << player.getMoney() << "$, et vous êtes sur la case " << c.getName() << std::endl;
}

void Display::displayDice(short dice1, short dice2)
{
	std::cout << "\n\n" << (selectDiceFace(dice1));						// Afficher le dé 1
	std::cout << (selectDiceFace(dice2)) << std::endl;					// Afficher le dé 2
	std::cout << "\n\tVous avez fait " << dice1 << " et " << dice2 << " !" << std::endl;	// Afficher les nombres
}

bool Display::displayBuyChoice(Case* attraction)
{
	char choice;

	do {
		std::cout << "\tCette attraction est disponible et coûte " << attraction->getPrice() << "$.\n"
			<< "\tVoulez vous acheter cette attraction ? (0 : non / 1 : oui) : " << std::endl;

		// Prendre un seul caractère sur l'entrée standard et ignorer les autres
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (choice != '0' && choice != '1');	// Vérification du choix

	choice -= '0';	// Passage du caractère à la valeur
	
	// Appliquer le choix
	if (choice == 1)
		std::cout << "\tVous possédez maintenant l'attraction " << attraction->getName() << std::endl;
	else
		std::cout << "\tVous avez refusé d'acheter l'attraction " << attraction->getName() << std::endl;

	// Envoyer le choix à l'algorythme du jeu
	return choice;
}

void Display::displayNotEnoughMoney()
{
	std::cout << "\tVous n'avez pas assez d'argent." << std::endl;
}

void Display::displayElimination(Joueur& player)
{
	std::cout << "\t/!\\ " << player.getName() << " : Vous n'avez plus d'argent et êtes donc éliminé /!\\" << std::endl;
}

void Display::displayFreeStand(Case& attraction, bool canBePlaced, Joueur oldOwner)
{
	if (canBePlaced)
		if (oldOwner.getName() != "None")
			std::cout << "\tVous avez placé un stand gratuit sur l'attraction \"" << attraction.getName() << "\", et avez pris cette attraction à " << oldOwner.getName() << " !" << std::endl;
		else
			std::cout << "\tVous avez placé un stand gratuit sur l'attraction \"" << attraction.getName() << "\" !" << std::endl;

	else
			std::cout << "\tVous ne pouvez pas placer de stand gratuit sur l'attraction \"" << attraction.getName() << "\"." << std::endl;

}

void Display::displayFreeStand(bool canBePlaced)
{
	if (canBePlaced)
		std::cout << "\tVous avez placé un stand gratuit !" << std::endl;

	else
		std::cout << "\tVous ne pouvez pas placer de stand gratuit." << std::endl;

}

void Display::displayCoffee(Joueur& joueur)
{
	std::cout << joueur.getName() << " : Vous êtes sur la case aller au café :  payez 3$ pout prendre le bus qui vous menera jusqu'a la case café sans prendre l'argent de la case départ."  << std::endl;
}

void Display::displayTrainStation()
{
	std::cout << "\tVous êtes dans une gare, relancez le dé !"  << std::endl;
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

void Display::displayVictory(Joueur& joueur)
{
	std::cout << "\n\tFélicitation " << joueur.getName() << ", vous avez gagné la partie !!!" << std::endl;
}

