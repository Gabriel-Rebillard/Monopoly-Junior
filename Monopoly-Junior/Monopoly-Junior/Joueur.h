#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Joueur
{

private:
std::string name;
short money;
short position;
public:

Joueur(const std::string& playerName);
std::string getName();
void modifyMoney(short montant);
void setPosition(short pos);
short getPosition();
short rollDice();
short getMoney();
};
