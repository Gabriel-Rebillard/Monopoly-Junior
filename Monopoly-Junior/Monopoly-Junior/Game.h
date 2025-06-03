#pragma once
#include <list>
#include <vector>
#include <fstream>
#include "Card.h"
#include "Joueur.h"
#include "Attraction.h"
#include "Fortune.h"

#define CHANCE_FILE_NAME "chance.txt"
#define CASES_FILE_NAME "cases.txt"

class Game {
private:
	std::vector<Case> cases;
	std::list<Card> cards;
	std::vector<Joueur> players;

	Case& getCase(short position);  
	void payerLoyer();              
	void placerStand();           
	void tirerCarte();      

	void flushCards();
	void createCases();
public:
	Game();                       
	void nextTurn();
	void addPlayer(Joueur& player);
};
