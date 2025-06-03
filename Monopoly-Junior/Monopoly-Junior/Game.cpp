#include "Game.h"

Game::Game()
{
	createCases();
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
	std::list<Card>::iterator index = cards.begin();
	short position = 0;


	//Remplir une première carte
	std::getline(chanceFile, line);
	Card card(line.substr(0, line.find(':')), std::stoi(line.substr(line.find(':') + 1)));
	cards.insert(index, card);

	//Mélanger les cartes
	while (std::getline(chanceFile, line)) {
		Card card(line.substr(0, line.find(':')), std::stoi(line.substr(line.find(':') + 1)));

		index = cards.begin();
		position = rand() % cards.size();
		for (short i = 0; i < position; i++)
			index++;
		
		cards.insert(index, card);
	}
	
	chanceFile.close();
}

void Game::createCases()
{
	std::ifstream caseFile(CASES_FILE_NAME);
	std::string line;
	std::string temp;

	for (short i = 0; i < 32; i++){
		temp = line.substr(2);
		if (line.at(0) == 'a') {
			Attraction c(temp.substr(0, temp.find(':')), std::stoi(temp.substr(temp.find(':') + 1)));
			cases.push_back(c);
		}
		else if (line.at(0) == 'f') {
			Fortune c(temp.substr(0, temp.find(':')));
			cases.push_back(c);
		}
		else {
			Case c(temp.substr(0, temp.find(':')));
			cases.push_back(c);
		}
	}
}	

#include <iostream>
void Game::nextTurn()
{
	for (short i = 0; i < cases.size(); i++) {
		std::cout << cases.at(i).getName() << std::endl;
	}
	
	for (short i = 0; i < cards.size(); i++) {
		std::cout << std::next(cards.begin(), i)->getText() << std::endl;
	}
	

}
