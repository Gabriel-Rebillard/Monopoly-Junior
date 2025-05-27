#include "Case.h"

Case::Case(const std::string& name, short position)
	: position(position), name(name)
{
}

short Case::getPosition()
{
	return position;
}

std::string& Case::getName()
{
	return name;
}
