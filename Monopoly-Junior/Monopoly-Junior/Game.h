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

class Game {
private:
    std::vector<Case*> cases;
    std::list<Card> cards;
    std::vector<Player> players;

    Display display;

    Case* getCase(short position);
    void payerLoyer();
    void placerStand();
    void tirerCarte();
    void flushCards();
    void createCases();

public:
    Game();

    void nextTurn();              
    void addPlayer(Player& player); 
};
