#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include "Case.h"
#include "Card.h"
#include <cstdlib>

#define CHANCE_FILE_NAME "chance.txt"
//#include "Player.h"

class Game {
private:
	std::vector<Case> cases;
	std::list<Card> cards;
	//std::vector<Player> players;

	Case& getCase(short position);  
	void payerLoyer();              
	void placerStand();           
	void tirerCarte();      

	void flushCards();
public:
	Game();                       
	void nextTurn();              
};
