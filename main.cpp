#include <iostream>
#include <Windows.h>
#include "Game.h"
#include "Joueur.h"

int main(void) {
	SetConsoleOutputCP(65001);
	srand((unsigned)time(NULL));

	Game game;

	char wait_char;
	std::cout << "\n\t\tMONOPOLY JUNIOR Version console";
	std::cout << "\n\nCommencer la partie ? (appuyez sur une touche puis Entrée) :";
	std::cin >> wait_char;



	// Demander le nombre de joueurs
	std::string resp;
	char nbPlayers;
	do {
		std::cout << "Combien de joueurs êtes vous ? (2 ~ 4) : ";
		std::cin >> resp;
		nbPlayers = resp.at(0);

		// Vérifier la saisie
		if (nbPlayers != '2' && nbPlayers != '3' && nbPlayers != '4')
			std::cout << "Veuillez rentrer un chiffre entre 2 et 4" << std::endl;

	} while (nbPlayers != '2' && nbPlayers != '3' && nbPlayers != '4');

	nbPlayers -= '0';



	// Demander le nom des joueurs
	for (short i = 1; i <= nbPlayers; i++){
		std::cout << "\nNom du " << i << "e joueur : ";
		std::cin >> resp;
		game.addPlayer(*new Joueur(resp));
	}


	// Boucle de jeu
	while (game.nextTurn()){
		std::cout << "\n\n\nProchain joueur ? (appuyez sur une touche puis Entrée) : ";
		std::cin >> wait_char;
	}

	return 0;
}