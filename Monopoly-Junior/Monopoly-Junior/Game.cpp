#include "Game.h"

Game::Game() {
    createCases();
    flushCards();
}

Case* Game::getCase(short position) {
    return cases.at(position);
}

void Game::payerLoyer() {
    void Game::payerLoyer()
{
	Joueur player = players.front();
	Case* c = getCase(player.getPosition());
	Joueur owner = *(c->getOwner());

	if (&owner != nullptr && owner.getName() != player.getName()) {
		short price = c->getPrice();
		player.modifyMoney(-price);
		owner.modifyMoney(price);
		display.displayRent(player, owner, price);
	}
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

short Game::tirerCarte() {
    short destination = cards.begin()->getDestination();
    
    display.displayCard(cards.begin()->getText());
    cards.insert(cards.end(), *cards.begin());
    cards.pop_front();
    
    return destination;
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

void Game::createCases()
{
	std::ifstream caseFile(CASES_FILE_NAME);
	std::string line;
	std::string temp;

	for (short i = 0; i < CASE_NUMBER; i++){
		std::getline(caseFile, line);
		temp = line.substr(2);

		if (line.at(0) == 'a') {
			Attraction* c = new Attraction(temp.substr(0, temp.find(':')), std::stoi(temp.substr(temp.find(':') + 1)));
			cases.push_back(c);
		}
		else if (line.at(0) == 'f') {
			Fortune* c = new Fortune(temp.substr(0, temp.find(':')));
			cases.push_back(c);
		}
		else {
			Case* c = new Case(temp.substr(0, temp.find(':')));
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

