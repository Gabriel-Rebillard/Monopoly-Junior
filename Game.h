#pragma once
#include <list>
#include <vector>
#include <fstream>
#include "Card.h"
#include "Joueur.h"

#include "Attraction.h"
#include "Fortune.h"

#include "Display.h"

#define CHANCE_FILE_NAME "chance.txt"
#define CASES_FILE_NAME "cases.txt"
#define CASE_NUMBER 32

enum CHANCE_POSITION { CHANCE_1 = 1, CHANCE_2 = 4, CHANCE_3 = 9, CHANCE_4 = 17, CHANCE_5 = 20, CHANCE_6 = 25 };
enum SHOW_POSITION { FIREWORKS = 8, DOLPHINS = 24 };
enum TRAIN_POSITION { YELLOW_TRAIN = 5, GREEN_TRAIN = 13, BLUE_TRAIN = 21, RED_TRAIN = 29 };
enum OTHER_EVENT_POSITION { START = 0, FORTUNE = 16, GO_TO_COFFE = 26 };

class Game {
private:
	std::vector<Case*> cases;
	std::list<Card> cards;
	std::vector<Joueur> players;
	short currentPlayerIndex;

	Display display;

	Case* getCase(short position);  
	short countRemainningPlayers();

	void payerLoyer();
	void placeFreeStand(short position);
	void buyStand();
	void placerStand();
	short tirerCarte();      


	void testElimination(Joueur& currentPlayer);


	bool caseAction(Joueur& currentPlayer, bool& reRollDices);
	bool chanceAction(Joueur& currentPlayer);
	bool trainAction();
	void showAction(Joueur& currentPlayer);
	void busAction(Joueur& currentPlayer);
	void startAction(Joueur& currentPlayer);
	void fortuneAction(Joueur& currentPlayer);
	void attractionAction(Joueur& currentPlayer);



	void flushCards();
	void createCases();

public:
	Game();                       
	bool nextTurn();
	void addPlayer(Joueur& player);
};
