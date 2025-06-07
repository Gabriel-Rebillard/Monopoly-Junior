#include "Game.h"
#include <iostream>
#include <cstdlib>

Game::Game() {
    createCases();
    flushCards();
}

Case& Game::getCase(short position) {
    return cases.at(position);
}

void Game::payerLoyer() {
    Player& joueur = players.front();
    Case& c = getCase(joueur.getPosition());

    Attraction* attraction = dynamic_cast<Attraction*>(&c);
    if (attraction && attraction->getProprio() != nullptr && attraction->getProprio() != &joueur) {
        joueur.modifyMoney(-attraction->getPrice());
        attraction->getProprio()->modifyMoney(attraction->getPrice());
        std::cout << joueur.getName() << " paie un loyer de " << (int)attraction->getPrice()
                  << " à " << attraction->getProprio()->getName() << std::endl;
    }
}

void Game::placerStand() {
    Player& joueur = players.front();
    Case& c = getCase(joueur.getPosition());

    Attraction* attraction = dynamic_cast<Attraction*>(&c);
    if (attraction && attraction->getProprio() == nullptr) {
        if (joueur.getMoney() >= attraction->getPrice()) {
            joueur.modifyMoney(-attraction->getPrice());
            attraction->setProprio(&joueur);
            std::cout << joueur.getName() << " achète " << c.getName() << " pour " << (int)attraction->getPrice() << std::endl;
        }
    }
}

void Game::tirerCarte() {
    if (cards.empty()) return;

    Card carte = cards.front();
    cards.pop_front();
    cards.push_back(carte);

    std::cout << "Carte tirée : " << carte.getText() << std::endl;

  
    players.front().setPosition(carte.getDestination());
}

void Game::flushCards() {
    std::ifstream chanceFile(CHANCE_FILE_NAME);
    std::string line;
    std::list<Card>::iterator index = cards.begin();
    short position = 0;

    if (std::getline(chanceFile, line)) {
        Card card(line.substr(0, line.find(':')), std::stoi(line.substr(line.find(':') + 1)));
        cards.insert(index, card);
    }

    while (std::getline(chanceFile, line)) {
        Card card(line.substr(0, line.find(':')), std::stoi(line.substr(line.find(':') + 1)));

        index = cards.begin();
        position = rand() % (cards.size() + 1);
        for (short i = 0; i < position; ++i)
            ++index;

        cards.insert(index, card);
    }

    chanceFile.close();
}

void Game::createCases() {
    std::ifstream caseFile(CASES_FILE_NAME);
    std::string line;
    std::string temp;

    for (short i = 0; i < 32 && std::getline(caseFile, line); i++) {
        temp = line.substr(2);  // Skip the prefix
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

    caseFile.close();
}

void Game::nextTurn() {
    Player& joueur = players.front();
    char dice = joueur.rollDice();
    short newPos = (joueur.getPosition() + dice) % cases.size();
    joueur.setPosition(newPos);

    std::cout << joueur.getName() << " lance le dé : " << (int)dice << " et arrive à la case " << getCase(newPos).getName() << std::endl;

    tirerCarte(); 
    payerLoyer();    
    placerStand();


    players.push_back(joueur);
    players.erase(players.begin());
}

void Game::addPlayer(Player& player) {
    players.push_back(player);
}

