#include <list>
#include <vector>
#include "Case.h"
#include "Card.h"
#include "Player.h"

class Game {
private:
	std::vector<Case> cases;
	std::list<Card> cards;
	std::vector<Player> players;

	Case getCase(short position);  
	void payerLoyer();              
	void placerStand();           
	void tirerCarte();              
public:
	Game();                       
	void nextTurn();              
};
