#include "Fortune.h"

Fortune::Fortune(const std::string& name)
	: money(0), Case(name)
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
