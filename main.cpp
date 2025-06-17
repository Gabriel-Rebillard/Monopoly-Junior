#include <iostream>
#include <Windows.h>
#include "Game.h"
#include "Joueur.h"

int main(void) {
	// Permet à la console d'afficher les caractère spéciaux et accentués
	SetConsoleOutputCP(65001);

	// Rendre l'aléatoire non répétitif à chaque exécution du programme
	srand((unsigned)time(NULL));

	Game game;

	char wait_char;	// Caractère utilisé pour attendre le joueur lors d'une fin de tour par exemple
	
	std::cout << "\n\t\tMONOPOLY JUNIOR Version console";
	std::cout << "\n\nCommencer la partie ? (appuyez sur une touche puis Entrée) :";
	std::cin >> wait_char;	// "wait_char" est ici utilisé pour attendre que le joueur lance la partie



	// Demander le nombre de joueurs
	std::string resp;
	char nbPlayers;
	do {
		std::cout << "Combien de joueurs êtes vous ? (2 ~ 4) : ";
		std::cin >> resp;
		nbPlayers = resp.at(0);	// Récupérer le premier caractère saisi

		// Vérifier la saisie
		if (nbPlayers != '2' && nbPlayers != '3' && nbPlayers != '4')
			std::cout << "Veuillez rentrer un chiffre entre 2 et 4" << std::endl;

	} while (nbPlayers != '2' && nbPlayers != '3' && nbPlayers != '4');

	nbPlayers -= '0';	// Convertir le caractère en entier



	// Demander le nom des joueurs
	for (short i = 1; i <= nbPlayers; i++){
		std::cout << "\nNom du " << i << "e joueur : ";
		std::cin >> resp;
		game.addPlayer(*new Joueur(resp));
	}


	// Boucle de jeu
	while (game.nextTurn()){	// nextTurn() renvoi 1 tant qu'il y'a au moins deux joueurs encore en jeu
		std::cout << "\n\n\nProchain joueur ? (appuyez sur une touche puis Entrée) : ";
		std::cin >> wait_char;
	}

	std::cout << "\n\n\nMerci d'avoir joué ! (appuyez sur une touche puis Entrée pour arreter le programme) : ";
	std::cin >> wait_char;
	
	return 0;
}
