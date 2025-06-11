#include "Game.h"

Game::Game()
{
	currentPlayerIndex = 0;
	createCases();
	flushCards();
}


Case* Game::getCase(short position)
{
	return cases.at(position);
}

short Game::countRemainningPlayers()
{
	short remainning = 0;
	for (auto& player : players)
		if (player.getMoney() > 0)
			remainning++;

	return remainning;
}

void Game::payerLoyer()
{
	Joueur& player = players.at(currentPlayerIndex);
	Case* c = getCase(player.getPosition());
	Joueur* owner = c->getOwner();

	if (owner != nullptr && owner->getName() != player.getName()) {
		short price = c->getPrice();
		player.modifyMoney(-price);
		owner->modifyMoney(price);
		display.displayRent(player, *owner, price);
	}
}

void Game::placeFreeStand(short position)
{
	Joueur& player = players.at(currentPlayerIndex);
	Case* stand = getCase(position);				// Attraction visée
	Case* previousCase = getCase(position - 1);		// Case précédant l'attraction visée
	Case* nextCase = getCase((position + 1) % 32);	// Case suivant l'attraction visée

	// Si la case précédente n'est pas une attraction
	if (previousCase->getOwner() == nullptr) {

		// Si il n'y a aucun joueur sur la case ou si le propriétaire n'est pas le même que celui de l'attraction voisine
		if (stand->getOwner()->getName() == "None" || stand->getOwner()->getName() != nextCase->getOwner()->getName()) {

			// Si le joueur est déjà propriétaire de l'attraction visée, il prend la case voisine
			if (stand->getOwner()->getName() == player.getName()) {
				display.displayFreeStand(*nextCase, true, *nextCase->getOwner());
				nextCase->setOwner(player);
			}

			// Sinon il prend l'attraction visée
			else {
				display.displayFreeStand(*stand, true, *stand->getOwner());
				stand->setOwner(player);
			}
		}

		// Si un joueur possède les deux attractions de la couleur
		else
			display.displayFreeStand(false);
	}

	// Si la case suivante n'est pas une attraction
	else {

		// Si il n'y a aucun joueur sur la case ou si le propriétaire n'est pas le même que celui de l'attraction voisine
		if (stand->getOwner()->getName() == "None" || stand->getOwner()->getName() != previousCase->getOwner()->getName()) {

			// Si le joueur est déjà propriétaire de l'attraction visée, il prend la case voisine
			if (stand->getOwner()->getName() == player.getName()) {
				display.displayFreeStand(*previousCase, true, *previousCase->getOwner());
				previousCase->setOwner(player);
			}

			// Sinon il prend l'attraction visée
			else {
				display.displayFreeStand(*stand, true, *stand->getOwner());
				stand->setOwner(player);
			}
		}

		// Si un joueur possède les deux attractions de la couleur
		else
			display.displayFreeStand(false);
	}
}

void Game::buyStand()
{
	Joueur& player = players.at(currentPlayerIndex);
	Case* stand = getCase(player.getPosition());

	if (player.getMoney() < stand->getPrice()) {
		display.displayNotEnoughMoney();
		return;
	}

	bool choice = display.displayBuyChoice(stand);
	if (choice) {
		player.modifyMoney(-stand->getPrice());
		placerStand();
	}
}

void Game::placerStand()
{
	Joueur& player = players.at(currentPlayerIndex);
	Case* property = getCase(player.getPosition());
	property->setOwner(player);
}

short Game::tirerCarte()
{
	short destination = cards.begin()->getDestination();
	display.displayCard(cards.begin()->getText());
	cards.insert(cards.end(), *cards.begin());
	cards.pop_front();
	return destination;
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
}	


bool Game::nextTurn()
{
	bool endOfTurn = false;
	bool reRollDices = true;
	short playerPosition;

	// Sauter les joueurs éliminés
	while (players.at(currentPlayerIndex).getMoney() <= 0)
		currentPlayerIndex++;

	Joueur& currentPlayer = players.at(currentPlayerIndex);
	display.displayTurnBeginning(currentPlayer, *getCase(currentPlayer.getPosition()));


	while (!endOfTurn) {

		// Lancer les dés
		if (reRollDices) {
			short dice1 = currentPlayer.rollDice();
			short dice2 = currentPlayer.rollDice();
			display.displayDice(dice1, dice2);

			playerPosition = currentPlayer.getPosition();

			// Modifier la position du joueur en fonction des dés
			currentPlayer.setPosition(currentPlayer.getPosition() + dice1 + dice2);

			// Vérifier si le joueur a passé la case départ
			if (currentPlayer.getPosition() != 0 && currentPlayer.getPosition() < playerPosition) {
				display.DisplayStartCase(currentPlayer, true);
				currentPlayer.modifyMoney(2);
			}

			reRollDices = false;
		}

		playerPosition = currentPlayer.getPosition();
		display.displayCase(*getCase(playerPosition));

		short destination;
		switch (playerPosition) {

			// Le joueur tombe sur une case chance
		case CHANCE_1: case CHANCE_2: case CHANCE_3: case CHANCE_4: case CHANCE_5: case CHANCE_6:
			destination = tirerCarte();
			if (destination < 32)
				currentPlayer.setPosition(destination);
			else {
				placeFreeStand(destination - 31);
				endOfTurn = true;
			}
			break;

			// Le joueur tombe sur une gare
		case YELLOW_TRAIN: case GREEN_TRAIN: case BLUE_TRAIN: case RED_TRAIN:
			display.displayTrainStation(currentPlayer);
			reRollDices = true;
			break;

			// Le joueur tombe sur une case spectacle
		case FIREWORKS: case DOLPHINS:
			display.displayShowCase(currentPlayer);
			currentPlayer.modifyMoney(-2);
			cases.at(FORTUNE)->addMoney(2);
			endOfTurn = true;
			break;

			// Le joueur tombe sur la case "Aller au café"
		case GO_TO_COFFE:
			display.displayCoffee(currentPlayer);
			currentPlayer.modifyMoney(-3);
			getCase(FORTUNE)->addMoney(3);
			currentPlayer.setPosition(10); // Mettre le joueur sur la case café
			endOfTurn = true;
			break;

			// Le joueur tombe sur la case départ
		case START:
			display.DisplayStartCase(currentPlayer, false);
			currentPlayer.modifyMoney(4);
			endOfTurn = true;
			break;

			// Le joueur tombe sur la case fortune
			short money;
		case FORTUNE:
			money = getCase(playerPosition)->getMoney();
			display.displayFortune(currentPlayer, money);
			currentPlayer.modifyMoney(money);
			endOfTurn = true;
			break;

			// Le joueur tombe sur la case café ou sur une attraction
		default :
			if (playerPosition != 10) {
				Case* property = getCase(playerPosition);
				if (property->getOwner() != nullptr) {
					if (property->getOwner()->getName() != "None")
						payerLoyer();
					else
						buyStand();
				}
			}
			endOfTurn = true;
		}
	}

	currentPlayerIndex = ++currentPlayerIndex == players.size() ? 0 : currentPlayerIndex;

	// Retourne true si il reste au moins deux joueurs
	return countRemainningPlayers() > 1;
}

void Game::addPlayer(Joueur& player)
{
	players.push_back(player);
}
