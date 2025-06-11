#include <iostream>
#include <Windows.h>
#include "Fortune.h"
#include "Game.h"
#include "Joueur.h"

int main(void) {
	SetConsoleOutputCP(65001);
	srand((unsigned)time(NULL));
	Game game;

	game.addPlayer(*new Joueur("Player 1"));
	game.addPlayer(*new Joueur("Player 2"));

	char wait_char;
	std::cout << "\n\t\tMONOPOLY JUNIOR Version console";
	std::cout << "\n\nCommencer la partie ? (appuyez sur une touche puis Entrée) :";
	std::cin >> wait_char;

	while (game.nextTurn()){
		std::cout << "\n\n\nProchain joueur ? (appuyez sur une touche puis Entrée) : ";
		std::cin >> wait_char;
	}

	return 0;
}