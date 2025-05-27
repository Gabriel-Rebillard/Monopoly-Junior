#include <iostream>

#include <vector>

#include <string>

#include <cstdlib>

#include <ctime>



// On suppose que les classes suivantes existent

#include "Joueur.h"

#include "Case.h"

#include "Game.h"



int main() {



int nbJoueurs;

std::cout << "Bienvenue dans Monopoly Junior !" << std::endl;



// Demander le nombre de joueurs





do {

std::cout << "Combien de joueurs ? (2 à 4) : ";

std::cin >> nbJoueurs;

} while (nbJoueurs < 2 || nbJoueurs > 4);


std::vector<Joueur*> joueurs;



// Saisie des noms des joueurs

for (int i = 0; i < nbJoueurs; ++i) {

std::string nom;

std::cout << "Nom du joueur " << i + 1 << " : ";

std::cin >> nom;

// Par défaut : 10€ d'argent, position 0

joueurs.push_back(new Joueur(nom, 10, 0));

}



// Création de quelques cases simples

std::vector<Case> cases = {

Case("Départ", 0),

Case("Attraction A", 1),

Case("Chance", 2),

Case("Attraction B", 3)

};



Game game;

game.players = joueurs;

game.cases = cases;



// Boucle de jeu

bool fin = false;

int tour = 0;




while (!fin) {

std::cout << "\n--- Tour " << tour + 1 << " ---" << std::endl;



for (auto* joueur : joueurs) {

std::cout << "Au tour de " << joueur->getName() << std::endl;

int lancer = joueur->rollDice();

std::cout << "Dé : " << lancer << std::endl;



int nouvellePos = (joueur->getPosition() + lancer) % cases.size();

joueur->setPosition(nouvellePos);



std::cout << joueur->getName() << " arrive sur " << cases[nouvellePos].getName() << std::endl;



// Gestion possible de l'effet de la case ici

}



tour++;



for (auto* joueur : joueurs) {

if (joueur->getMoney() <= 0) {

std::cout << joueur->getName() << " est ruiné ! Fin du jeu." << std::endl;

fin = true;

}

}

}



std::cout << "\nFin de la partie." << std::endl;

for (auto* joueur : joueurs) {

std::cout << joueur->getName() << " a " << int(joueur->getMoney()) << " euros." << std::endl;

}



// Libération mémoire

for (auto* joueur : joueurs) {

delete joueur;

}



return 0;
