#pragma once
#include <string>

class Case
{
protected:
	const short position;
	std::string name;

public:
	Case(const std::string& name, short position);
	short getPosition();
	std::string& getName();
};

