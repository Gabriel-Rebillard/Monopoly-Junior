#pragma once
#include "Case.h"

class Fortune : public Case
{
private:
	short money;

public:
	Fortune(const std::string& name);

	short getMoney();
	void addMoney(short amount);
};

