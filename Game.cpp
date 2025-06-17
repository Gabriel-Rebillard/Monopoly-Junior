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

	// Parcourir le vector de Joueurs
	for (auto& player : players)
		if (player.getMoney() > 0)
			remainning++;

	return remainning;
}

void Game::payerLoyer()
{
	Joueur& player = players.at(currentPlayerIndex);	// Joueur étant sur la case
	Case* c = getCase(player.getPosition());
	Joueur* owner = c->getOwner();						// Propriétaire de la case

	// Vérifier si la case est une attraction et si le joueur n'est pas le propriétaire
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

			// Si un joueur est déjà propriétaire de l'attraction visée, on place sur la case voisine si elle n'est pas occupée
			if (nextCase->getOwner()->getName() == "None" && stand->getOwner()->getName() != "None") {
				display.displayFreeStand(*nextCase, true, *nextCase->getOwner());
				nextCase->setOwner(player);
			}

			// Sinon on place sur l'attraction visée
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

			// Si le joueur est déjà propriétaire de l'attraction visée, on place sur la case voisine si elle n'est pas occupée
			if (previousCase->getOwner()->getName() == "None" && stand->getOwner()->getName() != "None") {
				display.displayFreeStand(*previousCase, true, *previousCase->getOwner());
				previousCase->setOwner(player);
			}

			// Sinon on place sur l'attraction visée
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

	// Vérifier si le joueur a assez d'argent
	if (player.getMoney() < stand->getPrice()) {
		display.displayNotEnoughMoney();
		return;
	}

	// Demander au joueur la confirmation d'achat
	bool choice = display.displayBuyChoice(stand);
	if (choice) {
		player.modifyMoney(-stand->getPrice());
		placerStand();
	}
}

void Game::placerStand()
{
	Joueur& player = players.at(currentPlayerIndex);
	Case* property = getCase(player.getPosition());		// Récupérer la case sur laquelle se trouve le joueur
	property->setOwner(player);
}

short Game::tirerCarte()
{
	short destination = cards.begin()->getDestination();
	display.displayCard(cards.begin()->getText());

	// Remettre la carte à la fin de la pile
	cards.insert(cards.end(), *cards.begin());
	cards.pop_front();

	return destination;
}

void Game::testElimination(Joueur& currentPlayer)
{
	if (currentPlayer.getMoney() <= 0)
		display.displayElimination(currentPlayer);
}

bool Game::caseAction(Joueur& currentPlayer, bool& reRollDices)
{
	bool endOfTurn;
	switch (currentPlayer.getPosition()) {

		// Le joueur tombe sur une case chance
	case CHANCE_1: case CHANCE_2: case CHANCE_3: case CHANCE_4: case CHANCE_5: case CHANCE_6:
		endOfTurn = chanceAction(currentPlayer);
		break;

		// Le joueur tombe sur une gare
	case YELLOW_TRAIN: case GREEN_TRAIN: case BLUE_TRAIN: case RED_TRAIN:
		reRollDices = trainAction();
		endOfTurn = false;
		break;

		// Le joueur tombe sur une case spectacle
	case FIREWORKS: case DOLPHINS:
		showAction(currentPlayer);
		endOfTurn = true;
		break;

		// Le joueur tombe sur la case "Aller au café"
	case GO_TO_COFFE:
		busAction(currentPlayer);
		endOfTurn = true;
		break;

		// Le joueur tombe sur la case départ
	case START:
		startAction(currentPlayer);
		endOfTurn = true;
		break;

		// Le joueur tombe sur la case fortune
	case FORTUNE:
		fortuneAction(currentPlayer);
		endOfTurn = true;
		break;

		// Le joueur tombe sur la case café ou sur une attraction
	default:
		attractionAction(currentPlayer);
		endOfTurn = true;
	}

	return endOfTurn;
}


bool Game::chanceAction(Joueur& currentPlayer)
{
	short destination = tirerCarte();

	// La carte envoie sur une case du plateau
	if (destination < 32) {
		currentPlayer.setPosition(destination);
		return false;
	}
	// La carte est un stand gratuit
	else {
		placeFreeStand(destination - 31);
		return true;
	}
}

bool Game::trainAction()
{
	display.displayTrainStation();
	return true;
}

void Game::showAction(Joueur& currentPlayer)
{
	display.displayShowCase(currentPlayer);
	currentPlayer.modifyMoney(-2);
	cases.at(FORTUNE)->addMoney(2);
}

void Game::busAction(Joueur& currentPlayer)
{
	display.displayCoffee(currentPlayer);
	currentPlayer.modifyMoney(-3);
	getCase(FORTUNE)->addMoney(3);
	currentPlayer.setPosition(10); // Mettre le joueur sur la case café
}

void Game::startAction(Joueur& currentPlayer)
{
	display.DisplayStartCase(currentPlayer, false);
	currentPlayer.modifyMoney(4);
}

void Game::fortuneAction(Joueur& currentPlayer)
{
	short money = getCase(currentPlayer.getPosition())->getMoney();
	display.displayFortune(currentPlayer, money);
	currentPlayer.modifyMoney(money);
}

void Game::attractionAction(Joueur& currentPlayer)
{
	if (currentPlayer.getPosition() != 10) {
		Case* attraction = getCase(currentPlayer.getPosition());
		if (attraction->getOwner() != nullptr) {
			if (attraction->getOwner()->getName() != "None")
				payerLoyer();
			else
				buyStand();
		}
	}
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
		// Créer la carte avec le texte et la destination contenus dans la ligne du fichier
		Card card(line.substr(0, line.find(':')), std::stoi(line.substr(line.find(':') + 1)));

		// Rendre l'index d'insertion aléatoire
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

	// Joueur propriétaire des attractions au début de la partie
	Joueur* nonePlayer = new Joueur("None");

	for (short i = 0; i < CASE_NUMBER; i++){
		// Lire une ligne du fichier
		std::getline(caseFile, line);

		// Enlever le préfixe 'x:'
		temp = line.substr(2);

		// Tester le préfixe
		if (line.at(0) == 'a') {
			// Créer une attraction avec le texte et le prix contenus dans la ligne du fichier
			Attraction* c = new Attraction(temp.substr(0, temp.find(':')), std::stoi(temp.substr(temp.find(':') + 1)), nonePlayer);
			cases.push_back(c);
		}
		else if (line.at(0) == 'f') {
			// Créer une attraction avec le texte contenus dans la ligne du fichier
			Fortune* c = new Fortune(temp.substr(0, temp.find(':')));
			cases.push_back(c);
		}
		else {
			// Créer une attraction avec le texte contenus dans la ligne du fichier
			Case* c = new Case(temp.substr(0, temp.find(':')));
			cases.push_back(c);
		}
	}

	caseFile.close();
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

		display.displayCase(*getCase(currentPlayer.getPosition()));

		// Effectuer l'action de la case sur laquelle le joueur tombe
		endOfTurn = caseAction(currentPlayer, reRollDices);
	}

	// Incrémenter le compteur joueur
	currentPlayerIndex = ++currentPlayerIndex == players.size() ? 0 : currentPlayerIndex;

	// Vérifie si le joueur courant est éliminé
	testElimination(currentPlayer);

	// Retourne true si il reste au moins deux joueurs
	return countRemainningPlayers() > 1;
}

void Game::addPlayer(Joueur& player)
{
	players.push_back(player);
}
