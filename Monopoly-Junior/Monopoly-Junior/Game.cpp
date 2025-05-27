#include "game.h"

Game::Game()
{
	flushCards();
}


Case& Game::getCase(short position)
{
	return cases.at(position);
}

void Game::payerLoyer()
{
}

void Game::placerStand()
{
}

void Game::tirerCarte()
{
	
}

void Game::flushCards()
{
	std::ifstream chanceFile(CHANCE_FILE_NAME);
	std::string line;
	std::list<Card>::iterator index;
	short position = 0;


	//Passer la première ligne du fichier
	std::getline(chanceFile, line);

	//Mélanger les cartes
	while (std::getline(chanceFile, line)) {
		Card card(line.substr(0, line.find(':')), std::stoi(line.substr(line.find(':') + 1)));

		index = cards.begin();
		position = rand() % cards.size();
		for (short i = 0; i < position; i++)
			index++;
		std::cout << position;
		
		cards.insert(index, card);
	}
}


void Game::nextTurn()
{
	std::list<Card>::iterator it;
	for (it = cards.begin(); it != cards.end(); ++it)
		std::cout << ' ' << it->getText() << std::endl;
}
