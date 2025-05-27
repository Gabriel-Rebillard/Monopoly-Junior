#include "Fortune.h"

Fortune::Fortune(const std::string& name, short position)
	: money(0), Case(name, position)
{
}

short Fortune::getMoney()
{
	short m = money;
	money = 0;
	return m;
}

void Fortune::addMoney(short amount)
{
	money += abs(amount);
}
